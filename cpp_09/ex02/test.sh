#!/bin/bash

./PmergeMe "0"
if grep -q "Is sorted" <<<"$(./PmergeMe "0")"; then
    echo ✅
else
    echo ❌
fi

./PmergeMe "`shuf -i 1-100000 -n 3000 | tr "\n" " "`"
if grep -q "Is sorted" <<<"$(./PmergeMe "0")"; then
    echo ✅
else
    echo ❌
fi

./PmergeMe "`shuf -i 1-100000 -n 15 | tr "\n" " "`"
if grep -q "Is sorted" <<<"$(./PmergeMe "0")"; then
    echo ✅
else
    echo ❌
fi
