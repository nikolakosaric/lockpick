################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
LED_matrix.obj: ../LED_matrix.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/hal/MSP430/MSP430F5529" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/lockpick" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --advice:power=all --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="LED_matrix.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

adc.obj: C:/Users/nikol/Documents/Spring\ 2018/Embedded\ Softwares/Embedded\ Softwares\ Fork/src/adc.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/hal/MSP430/MSP430F5529" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/lockpick" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --advice:power=all --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="adc.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

buffer.obj: C:/Users/nikol/Documents/Spring\ 2018/Embedded\ Softwares/Embedded\ Softwares\ Fork/src/buffer.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/hal/MSP430/MSP430F5529" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/lockpick" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --advice:power=all --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="buffer.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

buffer_printf.obj: C:/Users/nikol/Documents/Spring\ 2018/Embedded\ Softwares/Embedded\ Softwares\ Fork/src/buffer_printf.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/hal/MSP430/MSP430F5529" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/lockpick" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --advice:power=all --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="buffer_printf.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

hal_adc.obj: C:/Users/nikol/Documents/Spring\ 2018/Embedded\ Softwares/Embedded\ Softwares\ Fork/hal/MSP430/MSP430F5529/hal_adc.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/hal/MSP430/MSP430F5529" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/lockpick" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --advice:power=all --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="hal_adc.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

hal_uart.obj: C:/Users/nikol/Documents/Spring\ 2018/Embedded\ Softwares/Embedded\ Softwares\ Fork/hal/MSP430/MSP430F5529/hal_uart.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/hal/MSP430/MSP430F5529" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/lockpick" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --advice:power=all --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="hal_uart.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

list.obj: C:/Users/nikol/Documents/Spring\ 2018/Embedded\ Softwares/Embedded\ Softwares\ Fork/src/list.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/hal/MSP430/MSP430F5529" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/lockpick" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --advice:power=all --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="list.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

lockpick.obj: ../lockpick.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/hal/MSP430/MSP430F5529" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/lockpick" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --advice:power=all --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="lockpick.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/hal/MSP430/MSP430F5529" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/lockpick" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --advice:power=all --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="main.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

random_int.obj: C:/Users/nikol/Documents/Spring\ 2018/Embedded\ Softwares/Embedded\ Softwares\ Fork/src/random_int.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/hal/MSP430/MSP430F5529" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/lockpick" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --advice:power=all --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="random_int.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

subsystem.obj: C:/Users/nikol/Documents/Spring\ 2018/Embedded\ Softwares/Embedded\ Softwares\ Fork/src/subsystem.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/hal/MSP430/MSP430F5529" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/lockpick" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --advice:power=all --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="subsystem.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

task.obj: C:/Users/nikol/Documents/Spring\ 2018/Embedded\ Softwares/Embedded\ Softwares\ Fork/src/task.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/hal/MSP430/MSP430F5529" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/lockpick" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --advice:power=all --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="task.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

timing.obj: C:/Users/nikol/Documents/Spring\ 2018/Embedded\ Softwares/Embedded\ Softwares\ Fork/src/timing.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/hal/MSP430/MSP430F5529" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/lockpick" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --advice:power=all --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="timing.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

uart.obj: C:/Users/nikol/Documents/Spring\ 2018/Embedded\ Softwares/Embedded\ Softwares\ Fork/src/uart.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/include" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/Embedded Softwares Fork/hal/MSP430/MSP430F5529" --include_path="C:/Users/nikol/Documents/Spring 2018/Embedded Softwares/lockpick" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --advice:power=all --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="uart.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


