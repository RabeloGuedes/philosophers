#! /bin/bash

make re

valgrind --show-leak-kinds=all --leak-check=full --tool=helgrind ./philo 1 800 200 200 > philo_test_1
valgrind --show-leak-kinds=all --leak-check=full --tool=helgrind ./philo 5 800 200 200 > philo_test_2
valgrind --show-leak-kinds=all --leak-check=full --tool=helgrind ./philo 5 800 200 200 7 > philo_test_3
valgrind --show-leak-kinds=all --leak-check=full --tool=helgrind ./philo 4 410 200 200 > philo_test_4
valgrind --show-leak-kinds=all --leak-check=full --tool=helgrind ./philo 4 310 200 100 > philo_test_5
valgrind --show-leak-kinds=all --leak-check=full --tool=helgrind ./philo 2 500 200 100 > philo_test_6
valgrind --show-leak-kinds=all --leak-check=full --tool=helgrind ./philo 2 250 200 100 > philo_test_7
valgrind --show-leak-kinds=all --leak-check=full --tool=helgrind ./philo 2 150 200 100 > philo_test_8
valgrind --show-leak-kinds=all --leak-check=full --tool=helgrind ./philo 2 160 90 70 > philo_test_9
