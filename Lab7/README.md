# CS3220 Lab #7 : Systolic Array With AXIS

50 pts in total, will be rescaled into 13% of your final score of the course. 

**Part 1: Systolic Array With AXIS Protocol**: 100 pts

**Bonus: Backpressure Handling**: 40 pts

***Submission ddl***: Apr. 23rd

In this lab, you will explore the design of a systolic array interfacing AXI-stream (AXIS)protocol, which you have learned in lab 4.


## Part 1: Systolic Array With AXIS Protocol

The complete systolic array design with raw customized register interfaces is provided (the soln to the lab6-no-bonus except for the interface changes). You will need to modify the code to make it work with the AXIS protocol. 

**IMPORTANT NOTE**: The provided code will not work and contain syntax errors, as we directly change the interface of the systolic array to AXIS protocol without modifying the underlying logic of the entire design to handle the AXIS protocol. You will need to modify the code to make it work. However, you MUST NOT change the interface of the systolic array's top module [systolic_array.v](systolic_array.v).


**Lab6-solns**: By default, the skeleton is modified from that uses the soln to lab6-no-bonus and will fail for some sizes of M, N, K. If you want to use and start with the soln to lab6-with-bonus, plz refer to lab6_soln_w_bonus, i.e., take the MAC.v, ctrl.v and systolic_array.v from lab6_soln_w_bonus, and replace the interfaces of the new systolic_array.v with with the current one [systolic_array.v](systolic_array.v).


The code skeleton is provided in: 
- [systolic_array.v](systolic_array.v)
- [MAC.v](MAC.v)
- [ctrl.v](ctrl.v)
- [adder.v](adder.v)
- [multiplier.v](multiplier.v)

Out of the above files, you will need to work on [systolic_array.v](systolic_array.v), [MAC.v](MAC.v), and [ctrl.v](ctrl.v) to complete the systolic array design for Part 1.


Modify the code to make it work with the AXIS protocol.


**FIFO_DEPTH**: You may want to use [FIFO](synchronus_fifo.v) in many places. If you have not implemented the bonus part, you may want to use a large depth for some FIFO(s); that's why backpressure handling is important.

### Rules and Potential Violations (Will be enforced during grading)
1. adder and multiplier instances have to be used and used as they are
2. systolic array IOs **and** default parameters cannot be changed
3. for MAC's parameters, as long as we can pass the MULT_LAT parameter in from the top module (systolic_array.v), it's fine
4. Any changes to Makefile, test*.cpp, adder and multiplier module definition will not be considered

### Grading Details (It can take some time to run the tests; try picking out the individual test cases to run when debugging)

You design should be robust and the grading rubrics as follows:

- Test with `./run.sh test_systolic_array.cpp 100`
    - Test different `SEED` (**20pts**)
    - Test different `MULT_LAT` (Multiplier Latency) (**20pts**)
    - Test different `M` and `N` (**20pts**)
    - Test different `NUM` (**20pts**)
    - Test combined parameter sweep (**20pts**)



## Bonus: Backpressure Handling


In the above testing, we assume the input data is always valid for the systolic array to consume, and the tester's receiver is always ready to receive the output data from the systolic array. However, in practice, the communication between the systolic array and the tester is dynamic and backpressure-sensitive. It's possible that the tester's receiver is not ready to receive the output data from the systolic array, or the input data is not valid for the systolic array to consume. Therefore, whenever this happens, the systolic array should stall the input or output data to avoid data corruption.



- Test with `./run.sh test_systolic_array_random_drop.cpp 1000`
    - Test different `SEED` (**4pts**)
    - Test different `MULT_LAT` (Multiplier Latency) (**4pts**)
    - Test different `M` and `N` (**4pts**)
    - Test different `NUM` (**4pts**)
    - Test combined parameter sweep (**24pts**)

## Submission

+ Provide a zip file containing your source code. Generate the submission.zip file using the command `make submit`. Avoid manual zip file creation to prevent any issues with the autograding script, which could lead to a 30% score deduction.
* Late submission policy: 3 hours grace period. (Gradescope will be setup soon.)


