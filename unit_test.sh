#!/bin/bash

./main.exe matrix_1.txt matrix_2.txt -a
if [$( cmp -s result.txt add_out.txt)]
then
   echo "Addition test -- OK"
else
   echo "Addition test -- FAIL"
fi


./main.exe matrix_1.txt matrix_2.txt -m
if [$( cmp -s result.txt mul_out.txt)]
then
   echo "Multiplication test -- OK"
else
   echo "Multiplication test -- FAIL"
fi


./main.exe matrix_1.txt 
if [$( cmp -s result.txt inv_out.txt)]
then
   echo "Inversion 1 test -- OK"
else
   echo "Inversion 1 test -- FAIL"
fi


./main.exe matrix_2.txt
if [$( cmp -s result.txt add_out.txt)]
then
   echo "Inversion 2 test -- OK"
else
   echo "Inversion 2 test -- FAIL"
fi

./main.exe > result.txt
if [$( cmp -s result.txt err1_out.txt)]
then
   echo "Error situation test -- OK"
else
   echo "Error situation test -- FAIL"
fi