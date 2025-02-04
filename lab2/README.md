# CS3220 Lab #2 : Branch Prediction

100 pts in total, will be rescaled into 11.25% of your final score of the course.  

**Part 1: Baseline Branch Predictor**: 50 pts

**Part 2: Performance Measurement & Optimization**: 50 pts + 10 bonus pts (overflow allowed)

***Submission ddl***: Feb 17th

This lab is a continuation of lab #1. In this project, you will implement a branch predictor for your RISC-V CPU. You are suggested to work on top of the solution for lab #1 from the TAs, which are located in the current folder. Alternatively, you can copy your *.v and *.vh files from lab #1 here and start from your own implementation.

## Part 1: Baseline Branch Predictor (50 points): 

In this part, you'll be implementing a baseline branch predictor and a branch target buffer for your RISC-V CPU. Here's a concise overview of the design: 

The baseline design adopts a G-share branch predictor (please refer to lecture-6): 

1. The branch history register (BHR) has a length of 8 bits, you will use `PC[9:2] XOR BHR` to index a Pattern History Table (PHT).

+ BHR may be referred to as GHR ( "Global branch history register") in the slides, they are the same item.

2. The PHT is composed of 2^8 2-bit counters to make branch prediction. Each counter is initialized with 1 (indicating a weakly not taken).

3. The branch target buffer (BTB) has 16 entries, and you will use `PC[5:2]` to index it. Each entry of the BTB is composed of 3 parts: a valid bit, a tag field, and a target address:

+ the tag field is used to determine whether the current PC address in the FE stage is the one recorded in the BTB entry;
+ the valid bit is used to identify whether this entry contains a valid history, rather than unused;
+ the target address is used to predict the branch / jump target.


Summary of the G-share branch prediction algorithm: 

* FE Stage ([fe_stage.v](fe_stage.v)): 

    Both BTB and PHT are concurrently accessed in this stage. 
    
    1. If there's a BTB hit, use PHT outcome to determine the target address for the next instruction fetch: if the outcome is taken, use BTB target address. If BTB misses, use PC+4 for next instruction. 

    2. The address for the next instruction fetch and index (`PC[9:2] XOR BHR`) used in FE stage is passed to EX stage for PHT update.

* EX stage ([agex_stage.v](agex_stage.v)): 

    1. Check if the next instruction fecthed in the FE stage is correct or not: if not, flush the pipeline.

    - If the branch is taken, and the next instruction we fetched is not the branch target, we are supposed flush the pipeline;
    - If the branch is not taken, and the next instruction we fetched is not PC+4, we should flush the pipeline.

    2. For branch instructions (bne, beq, jalr, etc.), insert the target address into the BTB, no matter taken or not.
    
    3. If PHT is used for branching prediction in the FE stage, update PHT using the propagated PHT index (`PC[9:2] XOR BHR`). 

    4. Update the BHR. 

    + As BHR and PHT are implemented in the FE stage, you are supposed to forward the relevant signals to the FE stage for the updates mentioned in 2, 3 and 4 via from_AGEX_to_FE.

To pass earn full credit of this part, implement the baseline branch predictor described above and make sure your baseline branch predictor passes [testall.mem](/test/part4/testall.mem) and all testcases under part2.

**Grading**:
We will check the testcases are correctly executed or not.

There won’t be any performance improvement in testall.mem because the branch should always be predicted to not taken, since each branch instruction is executed only once (the branch predictor only works if you encounter same instruction multiple times).  

This testcase is only intend to test that the branch predictor you implement is not distructive for the other functionalities of the RISC-V processor. 


## Part 2: Performance Measurement & Optimization (50 points + 10 bonus pts)

1. [40 pts] For this part, you will evaluate branch prediction accuracy by adding counters to measure it (# of correctly predicted branches / # total branch instructions). Utilize the [towers.mem](test/towers/towers.mem) testcase for this assessment and write your measurement results in a pdf report. 

+ Note that jump instructions should be counted as branch instructions here as well.

+ The simulator may report that the simulation failed, this is intended and please ignore this message.

+ To gain credits from part-2, your baseline predictor should have > 30% accuracy. 

2. [10 pts + 10 pts bonus] Enhance the performance of your branch predictor on the [towers.mem](test/towers/towers.mem) testcase by making design changes: you can explore other BHR hashing functions (e.g. using different bits of PC for the XOR operation), or change the PHT or BTB sizes. Implement at least three different design changes, and present the corresponding performance outcomes in your report. If your modifications result in more than a 5% increase in prediction accuracy compared to the baseline branch predictor, you will earn 10 bonus points.

## Submission

+ Provide a zip file containing your source code for Part 1. Generate the submission.zip file using the command make submit. Avoid manual zip file creation to prevent any issues with the autograding script, which could lead to a 30% score deduction.

+ Submit a concise PDF report for Part 2 (limited to 2 pages) containing the following information:
1.  Your performance measurements for the baseline G-share branch predictor and your three variants.
2.  Discuss the design parameters that were modified and explain how these changes influenced branch prediction accuracy, either positively or negatively.
3. Do not put this pdf inside the zip file.
4. No need to submit code for Part 2.

<!-- Your scores will be depending on the performance improvement. If you get more than 5% performance improvement over the baseline configuration, you will receive 2 pts, if not, you will get 1 pt based on your report contents.  
Discuss your design space explorations and write a report about your evaluations. 
Evaluate your design with the provided benchmark and report the performance numbers. 
Please print out cycle count, BP accuracy (# of corrected predicted branch/# branch insts), # taken branches, # not-taken branches. # branches.  The cases are no branch predictor, baseline branch predictor (part-1), and your improved versions. Please show the results those are hurting the performance. 
Please show at least 3 different design changes that you have made in addition to the baseline branch predictor. Total 4 branch predictor's results + no branch predictor's result (project #1).  -->

<!-- **Grading**
The contents of the report will be used for the grading part-2.  
Please discuss what design parameters have you changed and discuss why it changes (good or bad or the same) performance.  


**What to submit** 
Report (max 2 pages) (No need to submit the code again)  -->

## FAQ 

[Q] I passed [testall.mem](test/part4/testall.mem) but failed to pass some testcases under [test/part2](test/part2). What should I do? \
[A] Please carefully check whether your when-to-flush logic is correctly implemented in the AGEX stage based on the following criteria: 

- If the branch is taken, and the next instruction we fetched is not the branch target, we are supposed flush the pipeline;

- If the branch is not taken, and the next instruction we fetched is not PC+4, we should flush the pipeline as well



[Q] I’m debugging my code. I see that there is an X in the BTB. How would it be possible? \
[A] FE stage can have pipeline bubbles. Therefore, BTB/BHT might be indexed with uninitialized values. Please make sure when you update BTB/BHT, only branch instructions/signals (not including X) can change the BTB/BHT values.

[Q] I don’t see performance improvement in testall.mem. Why?  \
[A] This is expected. All branch code in testall.mem are executed only once and not-taken. In order to make a branch predictor work, the processor has to see the same branch over and over. W/o training, the branch predictor would’t work well. 

[Q] Do we insert a BTB entry only for the taken branch or even when it is not taken? \
[A] You need to insert a BTB entry even the branch is not taken. Because the same branch might be taken in the next time. 

[Q] If we insert a not-taken branch for the BTB entry, what will be the target address? \
[A] You can still compute the target address as if it is taken and insert it in the BTB. 

[Q] What if the target in the BTB is wrong? \
[A] Just like a branch misprediction, we flush the pipeline and also update the BTB with the correct information. 

[Q] With a branch predictor, will the pipeline still have pipeline bubbles?  \
[A] The pipeline will have pipeline bubble for dependency stalls but not for branch instructions. 

[Q] My pipeline did not work for lab 1. What should I do?  \
[A] Please use the reference design provided by TAs instead. 

[Q] I want to add a new file (bp.v). can I? \
[A] Please do not add new file, as it might break our auto-grading script. 

[Q] Do I have to show the performance improvement in order to get a full-credit for part 1? \
[A] No. the performance improvement needs to be demonstrated in part 2 only. 

[Q] Are we expected to implement data forwarding in lab 2? \
[A] No.

[Q] Let’s say my instruction stream is as follows: 
```
BR(1)
ADD
BR(2)
```
. When BR(1) is in EX, it will update the BHR. But BR(2) will be in FE at that time.
Which value of BHR should FE use? The old value or the updated value from EX? \
[A] This is one of the optimization opportunities. So how you handle this case is up to you. Please remember that the branch predictor is just a predictor and it won't affect the correctness of the program. 

[Q] How to initialize PHT as one? \
[A] You should explicitly put 1s when it resets. 

[Q] I ran tower.mem and my test case is failed unlike other test cases. Is that expected?\
[A] Yes. The tower.mem returns "255", which does not match the PASS criteria of the simulator. You do not need to worry about it.
