# push_swap  

An efficient sorting algorithm implementation for the **push_swap** project using **Three-Way Quicksort**.  

## Introduction  

This project implements a highly optimized sorting algorithm for `push_swap`, inspired by [Ulysse Gerkens' article](https://medium.com/@ulysse.gerkens/push-swap-in-less-than-4200-operations-c292f034f6c0). The algorithm leverages **Three-Way Quicksort**, reducing the number of operations significantly.  

## Features  

- **Three-Way Quicksort** for efficient partitioning.  
- **Ring Buffer** for optimized command storage.  
- **High Performance**, achieving competitive move counts.  

## Operations
Visualization of operations and ring buffer usage:
![Operations](wiki/ops.png)

## Performance
Comparison of move counts in different cases. Thanks to [SimonCROS](https://github.com/SimonCROS/push_swap_tester) for the tester:
![Performance](wiki/performance.png)

## Installation  

1. Clone the repository:  
   ```sh
   git clone git@github.com:42Core-vvoronts/push_swap.git
   cd push_swap
   ```  
2. Compile the project:  
   ```sh
   make
   ```  

## Usage  

Run the program with a list of numbers:  
```sh
./push_swap 4 67 3 87 23  
``` 
