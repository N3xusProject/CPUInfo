/*
 *  MIT License
 *
 *  Copyright (c) 2022 Nexus-C, Ian Marco Moffett
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

#include <stdio.h>
#include <stdint.h>
#include <cpuinfo/cpuinfo.h>


// Returns a string "[]" if the condition is false
// otherwise it will retrurn "[+]"
char* check(uint8_t condition)
{
	if (condition)
	{
		return "[+]";
	}
	else 
	{
		return "[]";
	}
}



void list_features(void)
{
	printf("\n<==== Listing CPU Features ====>\n[+] => Supported, [] => Unsupported\n\n");
	printf("On-Chip Floating Point Unit %s\n", check(cpu_has_feature(CPU_FPU)));
	printf("Virtual Mode Extension %s\n", check(cpu_has_feature(CPU_VME)));
	printf("Debugging Extension %s\n", check(cpu_has_feature(CPU_DE)));
	printf("Page Size Extension %s\n", check(cpu_has_feature(CPU_PSE)));
	printf("Time Stamp Counter %s\n", check(cpu_has_feature(CPU_TSC)));
	printf("Model Specific Registers %s\n", check(cpu_has_feature(CPU_MSR)));
	printf("Physical Address Extension %s\n", check(cpu_has_feature(CPU_PAE)));
	printf("Model Check Exception %s\n", check(cpu_has_feature(CPU_MSE)));
	printf("CMPXCHG8 Instruction %s\n", check(cpu_has_feature(CPU_CX8)));
	printf("APIC %s\n", check(cpu_has_feature(CPU_APIC)));
}



int main(void)
{
	printf("CPU VENDOR - %s\n", cpu_get_vendor());
	list_features();
	return 0;
}
