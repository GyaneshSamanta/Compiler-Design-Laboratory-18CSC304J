# Experiment 2

`Overview`

In this experiment we showcase the transition state table whilst a regular expression is converted to NFA. 

`Code Explanation`

The regular expression is stored in a 1D Array `reg` and the transition table output is stored in the 2D Array.

Initially all values in the 2D array are 0.

In the if-else section we follow [Thompson Construction](https://medium.com/swlh/visualizing-thompsons-construction-algorithm-for-nfas-step-by-step-f92ef378581b) to classify the inputs into kleen closure, concantenation and union. Based on the input received and the construction model, we store in the values in the 2D array and display it.

