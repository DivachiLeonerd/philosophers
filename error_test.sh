make re && clear

printf "\033[0;33m"
printf "/////////////////////////////////////////\n"
printf "	Error Testing Philosophers\n"
printf "/////////////////////////////////////////\n\n"
printf "\033[0m"

printf "\033[0;31mWithout Arguments 💩\n\033[0m"
printf "\033[0;97mTest -> ./philo\n\033[0m"
./philo
printf "\n"

printf "\033[0;31mWith less than 3 Arguments 💩\n\033[0m"
printf "\033[0;97mTest -> ./philo 123 123\n\033[0m"
./philo 123 123
printf "\n"

printf "\033[0;31mWith more than 5 Arguments 💩\n\033[0m"
printf "\033[0;97mTest -> ./philo 123 123 123 123 123 123\n\033[0m"
./philo 123 123 123 123 123 123
printf "\n"

printf "\033[0;31mWith negative Arguments 💩\n\033[0m"
printf "\033[0;97mTest -> ./philo 123 -123 123 123\n\033[0m"
./philo 123 -123 123 123
printf "\n"

printf "\033[0;31mWith one argument being 0 💩\n\033[0m"
printf "\033[0;97mTest -> ./philo 123 0 123 123\n\033[0m"
./philo 123 0 123 123
printf "\n"

printf "\033[0;31mWithout Numbers 💩\n\033[0m"
printf "\033[0;97mTest -> ./philo arroz batata milho laranja\n\033[0m"
./philo arroz batata milho laranja
printf "\n"

printf "\033[0;31mWith Numbers and Letters 💩\n\033[0m"
printf "\033[0;97mTest -> ./philo 123 ba15ta 25 laranja\n\033[0m"
./philo 123 ba15ta 25 laranja
printf "\n"

printf "\033[0;31mWith numbers biggers than max int 💩\n\033[0m"
printf "\033[0;97mTest -> ./philo 5 2147483648 3147483647 214748\n\033[0m"
./philo 5 2147483648 3147483647 214748
printf "\n"

printf "\033[0;31mWith numbers and letters 💩\n\033[0m"
printf "\033[0;97mTest -> ./philo 5 1 1-23 123 123\n\033[0m"
./philo 5 1 1-23 123 123
printf "\n"

printf "\033[0;31mWith numbers and letters 💩\n\033[0m"
printf "\033[0;97mTest -> ./philo 5 1 123- 123 123\n\033[0m"
./philo 5 1 123- 123 123
printf "\n"

printf "\033[0;31mWith numbers and letters 💩\n\033[0m"
printf "\033[0;97mTest -> ./philo 5 1 123a 123 123\n\033[0m"
./philo 5 1 123a 123 123
printf "\n"
