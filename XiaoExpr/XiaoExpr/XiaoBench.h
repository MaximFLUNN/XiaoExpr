#pragma once
#include <iostream>
#include <ctime> 
// todo написать авто спавн функций

// Xiao | Tiny

namespace XE {

	namespace Bench {

		std::vector<std::string> plus_minus_bench; // +
		std::vector<std::string> plus_minus_brackets_bench; // +
		std::vector<std::string> plus_minus_var_bench; // +
		std::vector<std::string> plus_minus_brackets_var_bench; // +
		std::vector<std::string> multiply_devide_bench; // +
		std::vector<std::string> multiply_brackets_devide_bench; // +
		std::vector<std::string> multiply_devide_var_bench; // +
		std::vector<std::string> multiply_brackets_devide_var_bench; // +
		std::vector<std::string> factorial_bench; // +
		std::vector<std::string> brackets_factorial_bench; // +
		std::vector<std::string> factorial_var_bench; // +
		std::vector<std::string> brackets_factorial_var_bench; // +
		std::vector<std::string> functions_in_row_bench; // + 
		std::vector<std::string> functions_brackets_in_row_bench; // +
		std::vector<std::string> functions_in_row_var_bench; // +
		std::vector<std::string> functions_brackets_in_row_var_bench; // +
		std::vector<std::string> more_collections_of_functions_bench; // +
		std::vector<std::string> more_collections_of_functions_brackets_bench; // +
		std::vector<std::string> more_collections_of_functions_var_bench; // +
		std::vector<std::string> more_collections_of_functions_var_brackets_bench; // +
		std::vector<std::string> unrealistic_more_replacement_var_bench; // +
		std::vector<std::string> unrealistic_more_replacement_var_brackets_bench; // +
		std::vector<std::string> unrealistic_more_replacement_var_in_functions_in_row_bench; // +
		std::vector<std::string> unrealistic_more_replacement_var_in_functions_in_row_brackets_bench; // +
		std::vector<std::string> unrealistic_more_replacement_var_in_more_collections_functions_bench; // +
		std::vector<std::string> unrealistic_more_replacement_var_in_more_collections_functions_brackets_bench; // +

		std::vector<std::vector<std::string>> all_benchs = {
			plus_minus_bench, // +
			plus_minus_brackets_bench, // +
			plus_minus_var_bench, // +
			plus_minus_brackets_var_bench, // +
			multiply_devide_bench, // +
			multiply_brackets_devide_bench, // +
			multiply_devide_var_bench, // +
			multiply_brackets_devide_var_bench, // +
			factorial_bench, // +
			brackets_factorial_bench, // +
			factorial_var_bench, // +
			brackets_factorial_var_bench, // +
			functions_in_row_bench, // + 
			functions_brackets_in_row_bench, // +
			functions_in_row_var_bench, // +
			functions_brackets_in_row_var_bench, // +
			more_collections_of_functions_bench, // +
			more_collections_of_functions_brackets_bench, // +
			more_collections_of_functions_var_bench, // +
			more_collections_of_functions_var_brackets_bench, // +
			unrealistic_more_replacement_var_bench, // +
			unrealistic_more_replacement_var_brackets_bench, // +
			unrealistic_more_replacement_var_in_functions_in_row_bench, // +
			unrealistic_more_replacement_var_in_functions_in_row_brackets_bench, // +
			unrealistic_more_replacement_var_in_more_collections_functions_bench, // +
			unrealistic_more_replacement_var_in_more_collections_functions_brackets_bench // +
		};
	}

	namespace Generator {

		bool random_srand = false;

		void CheckSeed() {
			if (!random_srand) {
				srand(time(NULL));
				random_srand = !random_srand;
			}
		}

		int Rand(int min, int max) {
			CheckSeed();
			return (rand() % (max - min) + min);
		}

		int GenerateRandomIntNumber(int size) {
			CheckSeed();
			int limit_max = 9;
			int value = 9;
			for (; size > 1; size--) {
				value = (value * 10) + 9;
			}
			return Rand(1, value);
		}

		double GenerateRandomDoubleNumber(int size) {
			return GenerateRandomIntNumber(size) + (GenerateRandomIntNumber(size) * 0.00001);
		}

		std::string GenerateRandomSignPlusMinus() {
			if (Rand(0, 2)) {
				return "+";
			}
			else {
				return "-";
			}
		}

		std::string GenerateRandomSignMultiplyDevide() {
			if (Rand(0, 2)) {
				return "*";
			}
			else {
				return "/";
			}
		}

		char GenerateRandomVar() {
			if (Rand(0, 2)) {
				return Rand(START_LOWERCASE_LETTER, END_LOWERCASE_LETTER);
			}
			else {
				return Rand(START_UPPERCASE_LETTER, END_UPPERCASE_LETTER);
			}
		}

		std::vector<std::string> func_alphabet = {
			"abs",
			"ceil",
			"floor",
			"cos",
			"sin",
			"tan",
			"log",
			"sqrt",
			//"log10",
			//"acos",
			//"asin",
			//"sinh",
			//"cosh",
			//"atan2",
			//"pow"
		};

		std::string once_func = "abs";

		std::string GenerateRandomFunction() {
			return func_alphabet[Rand(NULL, func_alphabet.size() - 1)];
		}

		std::string GenerateRandomFunctionOnce() {
			return once_func;
		}

		std::vector<std::string> schemes = {
			"[gn1]", "[gn2]", "[gn3]", "[gn4]", "[gn5]",
			"[gfn1]", "[gfn2]", "[gfn3]", "[gfn4]", "[gfn5]",
			"[gspm]", "[gsmd]", "[gv]", "[gf]", "[gfo]"
		};

		std::string GenerateTerm(std::string part) {
			if (part == schemes[0]) {
				return std::to_string(GenerateRandomIntNumber(1));
			}
			else if (part == schemes[1]) {
				return std::to_string(GenerateRandomIntNumber(2));
			}
			else if (part == schemes[2]) {
				return std::to_string(GenerateRandomIntNumber(3));
			}
			else if (part == schemes[3]) {
				return std::to_string(GenerateRandomIntNumber(4));
			}
			else if (part == schemes[4]) {
				return std::to_string(GenerateRandomIntNumber(5));
			}
			else if (part == schemes[5]) {
				return std::to_string(GenerateRandomDoubleNumber(1));
			}
			else if (part == schemes[6]) {
				return std::to_string(GenerateRandomDoubleNumber(2));
			}
			else if (part == schemes[7]) {
				return std::to_string(GenerateRandomDoubleNumber(3));
			}
			else if (part == schemes[8]) {
				return std::to_string(GenerateRandomDoubleNumber(4));
			}
			else if (part == schemes[9]) {
				return std::to_string(GenerateRandomDoubleNumber(5));
			}
			else if (part == schemes[10]) {
				return GenerateRandomSignPlusMinus();
			}
			else if (part == schemes[11]) {
				return GenerateRandomSignMultiplyDevide();
			}
			else if (part == schemes[12]) {
				return std::string() + GenerateRandomVar();
			}
			else if (part == schemes[13]) {
				return GenerateRandomFunction();
			}
			else if (part == schemes[14]) {
				return GenerateRandomFunctionOnce();
			}
			else {
				std::cout << "\nError epta, part: " << part << "\n";
				return "error";
			}
		}

		std::string GenerateExpr(std::string scheme) {
			std::string out;
			int size = scheme.size();
			bool read_replace_word = false;
			std::string replace_word = "";
			for (int i = 0; i < size; i++) {
				if (scheme[i] == '[') {
					read_replace_word = true;
				}
				else if (scheme[i] == ']') {
					read_replace_word = false;
					replace_word += scheme[i];
					out += GenerateTerm(replace_word);
					replace_word = "";
					continue;
				}
				if (read_replace_word) {
					replace_word += scheme[i];
				}
				else {
					out += scheme[i];
				}
			}
			return out;
		}

		std::string plus_minus_scheme[10] = {
			"[gn1] [gspm] [gn1] [gspm] [gn1] [gspm] [gn1] [gspm] [gn1]",
			"[gn2] [gspm] [gn2] [gspm] [gn2] [gspm] [gn2] [gspm] [gn2] [gspm] [gn2]",
			"[gn3] [gspm] [gn3] [gspm] [gn3] [gspm] [gn3] [gspm] [gn3] [gspm] [gn3] [gspm] [gn3]",
			"[gn4] [gspm] [gn4] [gspm] [gn4] [gspm] [gn4] [gspm] [gn4] [gspm] [gn4] [gspm] [gn4] [gspm] [gn4]",
			"[gn5] [gspm] [gn5] [gspm] [gn5] [gspm] [gn5] [gspm] [gn5] [gspm] [gn5] [gspm] [gn5] [gspm] [gn5] [gspm] [gn5]",
			"[gfn1] [gspm] [gfn1] [gspm] [gfn1] [gspm] [gfn1] [gspm] [gfn1] [gspm] [gfn1] [gspm] [gfn1] [gspm] [gfn1] [gspm] [gfn1]",
			"[gfn2] [gspm] [gfn2] [gspm] [gfn2] [gspm] [gfn2] [gspm] [gfn2] [gspm] [gfn2] [gspm] [gfn2] [gspm] [gfn2] [gspm] [gfn2] [gspm] [gfn2]",
			"[gfn3] [gspm] [gfn3] [gspm] [gfn3] [gspm] [gfn3] [gspm] [gfn3] [gspm] [gfn3] [gspm] [gfn3] [gspm] [gfn3] [gspm] [gfn3] [gspm] [gfn3] [gspm] [gfn3]",
			"[gfn4] [gspm] [gfn4] [gspm] [gfn4] [gspm] [gfn4] [gspm] [gfn4] [gspm] [gfn4] [gspm] [gfn4] [gspm] [gfn4] [gspm] [gfn4] [gspm] [gfn4] [gspm] [gfn4] [gspm] [gfn4]",
			"[gfn5] [gspm] [gfn5] [gspm] [gfn5] [gspm] [gfn5] [gspm] [gfn5] [gspm] [gfn5] [gspm] [gfn5] [gspm] [gfn5] [gspm] [gfn5] [gspm] [gfn5] [gspm] [gfn5] [gspm] [gfn5] [gspm] [gfn5]",
		};

		std::string plus_minus_brackets_scheme[10] = {
			"(([gn1] [gspm] (([gn1] [gspm] [gn1]) [gspm] [gn1])) [gspm] [gn1])",
			"((([gn2] [gspm] (([gn2] [gspm] [gn2]) [gspm] [gn2])) [gspm] [gn2]) [gspm] [gn2])",
			"(((([gn3] [gspm] (([gn3] [gspm] [gn3]) [gspm] [gn3])) [gspm] [gn3]) [gspm] [gn3]) [gspm] [gn3])",
			"((((([gn4] [gspm] (([gn4] [gspm] [gn4]) [gspm] [gn4])) [gspm] [gn4]) [gspm] [gn4]) [gspm] [gn4]) [gspm] [gn4])",
			"(((((([gn5] [gspm] (([gn5] [gspm] [gn5]) [gspm] [gn5])) [gspm] [gn5]) [gspm] [gn5]) [gspm] [gn5]) [gspm] [gn5]) [gspm] [gn5])",
			"(((([gfn1] [gspm] [gfn1]) [gspm] ([gfn1] [gspm] [gfn1])) [gspm] (([gfn1] [gspm] [gfn1]) [gspm] ([gfn1] [gspm] [gfn1]))) [gspm] [gfn1])",
			"((((([gfn2] [gspm] [gfn2]) [gspm] ([gfn2] [gspm] [gfn2])) [gspm] (([gfn2] [gspm] [gfn2]) [gspm] ([gfn2] [gspm] [gfn2]))) [gspm] [gfn2]) [gspm] [gfn2])",
			"(((((([gfn3] [gspm] [gfn3]) [gspm] ([gfn3] [gspm] [gfn3])) [gspm] (([gfn3] [gspm] [gfn3]) [gspm] ([gfn3] [gspm] [gfn3]))) [gspm] [gfn3]) [gspm] [gfn3]) [gspm] [gfn3])",
			"((((((([gfn4] [gspm] [gfn4]) [gspm] ([gfn4] [gspm] [gfn4])) [gspm] (([gfn4] [gspm] [gfn4]) [gspm] ([gfn4] [gspm] [gfn4]))) [gspm] [gfn4]) [gspm] [gfn4]) [gspm] [gfn4]) [gspm] [gfn4])",
			"(((((((([gfn5] [gspm] [gfn5]) [gspm] ([gfn5] [gspm] [gfn5])) [gspm] (([gfn5] [gspm] [gfn5]) [gspm] ([gfn5] [gspm] [gfn5]))) [gspm] [gfn5]) [gspm] [gfn5]) [gspm] [gfn5]) [gspm] [gfn5]) [gspm] [gfn5])",
		};

		std::string plus_minus_var_scheme[10] = {
			"[gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv]",
			"[gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv]",
			"[gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv]",
			"[gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv]",
			"[gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv]",
			"[gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv]",
			"[gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv]",
			"[gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv]",
			"[gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv]",
			"[gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv]",
		};

		std::string plus_minus_brackets_var_scheme[10] = {
			"(([gv] [gspm] (([gv] [gspm] [gv]) [gspm] [gv])) [gspm] [gv])",
			"((([gv] [gspm] (([gv] [gspm] [gv]) [gspm] [gv])) [gspm] [gv]) [gspm] [gv])",
			"(((([gv] [gspm] (([gv] [gspm] [gv]) [gspm] [gv])) [gspm] [gv]) [gspm] [gv]) [gspm] [gv])",
			"((((([gv] [gspm] (([gv] [gspm] [gv]) [gspm] [gv])) [gspm] [gv]) [gspm] [gv]) [gspm] [gv]) [gspm] [gv])",
			"(((((([gv] [gspm] (([gv] [gspm] [gv]) [gspm] [gv])) [gspm] [gv]) [gspm] [gv]) [gspm] [gv]) [gspm] [gv]) [gspm] [gv])",
			"(((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv]))) [gspm] [gv])",
			"((((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv]))) [gspm] [gv]) [gspm] [gv])",
			"(((((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv]))) [gspm] [gv]) [gspm] [gv]) [gspm] [gv])",
			"((((((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv]))) [gspm] [gv]) [gspm] [gv]) [gspm] [gv]) [gspm] [gv])",
			"(((((((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv]))) [gspm] [gv]) [gspm] [gv]) [gspm] [gv]) [gspm] [gv]) [gspm] [gv])",
		};

		std::string multiply_devide_scheme[10] = {
			"[gn1] [gsmd] [gn1] [gsmd] [gn1] [gsmd] [gn1] [gsmd] [gn1]",
			"[gn2] [gsmd] [gn2] [gsmd] [gn2] [gsmd] [gn2] [gsmd] [gn2] [gsmd] [gn2]",
			"[gn2] [gsmd] [gn2] [gsmd] [gn2] [gsmd] [gn2] [gsmd] [gn2] [gsmd] [gn2] [gsmd] [gn2]",
			"[gn3] [gsmd] [gn3] [gsmd] [gn3] [gsmd] [gn3] [gsmd] [gn3] [gsmd] [gn3] [gsmd] [gn3] [gsmd] [gn3]",
			"[gn3] [gsmd] [gn3] [gsmd] [gn3] [gsmd] [gn3] [gsmd] [gn3] [gsmd] [gn3] [gsmd] [gn3] [gsmd] [gn3] [gsmd] [gn3]",
			"[gfn1] [gsmd] [gfn1] [gsmd] [gfn1] [gsmd] [gfn1] [gsmd] [gfn1] [gsmd] [gfn1] [gsmd] [gfn1] [gsmd] [gfn1] [gsmd] [gfn1]",
			"[gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2]",
			"[gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2]",
			"[gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn3] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2]",
			"[gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn3] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2] [gsmd] [gfn2]",
		};

		std::string multiply_brackets_devide_scheme[10]{
			"(([gn1] [gsmd] (([gn1] [gsmd] [gn1]) [gsmd] [gn1])) [gsmd] [gn1])",
			"((([gn2] [gsmd] (([gn2] [gsmd] [gn2]) [gsmd] [gn2])) [gsmd] [gn2]) [gsmd] [gn2])",
			"(((([gn2] [gsmd] (([gn2] [gsmd] [gn2]) [gsmd] [gn2])) [gsmd] [gn2]) [gsmd] [gn2]) [gsmd] [gn2])",
			"((((([gn3] [gsmd] (([gn3] [gsmd] [gn3]) [gsmd] [gn3])) [gsmd] [gn3]) [gsmd] [gn3]) [gsmd] [gn3]) [gsmd] [gn3])",
			"(((((([gn3] [gsmd] (([gn3] [gsmd] [gn3]) [gsmd] [gn3])) [gsmd] [gn3]) [gsmd] [gn3]) [gsmd] [gn3]) [gsmd] [gn3]) [gsmd] [gn3])",
			"(((([gfn1] [gsmd] [gfn1]) [gsmd] ([gfn1] [gsmd] [gfn1])) [gsmd] (([gfn1] [gsmd] [gfn1]) [gsmd] ([gfn1] [gsmd] [gfn1]))) [gsmd] [gfn1])",
			"((((([gfn2] [gsmd] [gfn2]) [gsmd] ([gfn2] [gsmd] [gfn2])) [gsmd] (([gfn2] [gsmd] [gfn2]) [gsmd] ([gfn2] [gsmd] [gfn2]))) [gsmd] [gfn2]) [gsmd] [gfn2])",
			"(((((([gfn2] [gsmd] [gfn2]) [gsmd] ([gfn2] [gsmd] [gfn2])) [gsmd] (([gfn2] [gsmd] [gfn2]) [gsmd] ([gfn2] [gsmd] [gfn2]))) [gsmd] [gfn2]) [gsmd] [gfn2]) [gsmd] [gfn2])",
			"((((((([gfn2] [gsmd] [gfn2]) [gsmd] ([gfn3] [gsmd] [gfn2])) [gsmd] (([gfn3] [gsmd] [gfn2]) [gsmd] ([gfn2] [gsmd] [gfn2]))) [gsmd] [gfn2]) [gsmd] [gfn2]) [gsmd] [gfn2]) [gsmd] [gfn2])",
			"(((((((([gfn2] [gsmd] [gfn2]) [gsmd] ([gfn3] [gsmd] [gfn2])) [gsmd] (([gfn3] [gsmd] [gfn2]) [gsmd] ([gfn2] [gsmd] [gfn2]))) [gsmd] [gfn2]) [gsmd] [gfn2]) [gsmd] [gfn2]) [gsmd] [gfn2]) [gsmd] [gfn2])",
		};

		std::string multiply_devide_var_scheme[10] = {
			"[gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv]",
			"[gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv]",
			"[gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv]",
			"[gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv]",
			"[gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv]",
			"[gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv]",
			"[gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv]",
			"[gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv]",
			"[gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv]",
			"[gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv] [gsmd] [gv]",
		};

		std::string multiply_brackets_devide_var_scheme[10] = {
			"(([gv] [gsmd] (([gv] [gsmd] [gv]) [gsmd] [gv])) [gsmd] [gv])",
			"((([gv] [gsmd] (([gv] [gsmd] [gv]) [gsmd] [gv])) [gsmd] [gv]) [gsmd] [gv])",
			"(((([gv] [gsmd] (([gv] [gsmd] [gv]) [gsmd] [gv])) [gsmd] [gv]) [gsmd] [gv]) [gsmd] [gv])",
			"((((([gv] [gsmd] (([gv] [gsmd] [gv]) [gsmd] [gv])) [gsmd] [gv]) [gsmd] [gv]) [gsmd] [gv]) [gsmd] [gv])",
			"(((((([gv] [gsmd] (([gv] [gsmd] [gv]) [gsmd] [gv])) [gsmd] [gv]) [gsmd] [gv]) [gsmd] [gv]) [gsmd] [gv]) [gsmd] [gv])",
			"(((([gv] [gsmd] [gv]) [gsmd] ([gv] [gsmd] [gv])) [gsmd] (([gv] [gsmd] [gv]) [gsmd] ([gv] [gsmd] [gv]))) [gsmd] [gv])",
			"((((([gv] [gsmd] [gv]) [gsmd] ([gv] [gsmd] [gv])) [gsmd] (([gv] [gsmd] [gv]) [gsmd] ([gv] [gsmd] [gv]))) [gsmd] [gv]) [gsmd] [gv])",
			"(((((([gv] [gsmd] [gv]) [gsmd] ([gv] [gsmd] [gv])) [gsmd] (([gv] [gsmd] [gv]) [gsmd] ([gv] [gsmd] [gv]))) [gsmd] [gv]) [gsmd] [gv]) [gsmd] [gv])",
			"((((((([gv] [gsmd] [gv]) [gsmd] ([gv] [gsmd] [gv])) [gsmd] (([gv] [gsmd] [gv]) [gsmd] ([gv] [gsmd] [gv]))) [gsmd] [gv]) [gsmd] [gv]) [gsmd] [gv]) [gsmd] [gv])",
			"(((((((([gv] [gsmd] [gv]) [gsmd] ([gv] [gsmd] [gv])) [gsmd] (([gv] [gsmd] [gv]) [gsmd] ([gv] [gsmd] [gv]))) [gsmd] [gv]) [gsmd] [gv]) [gsmd] [gv]) [gsmd] [gv]) [gsmd] [gv])",
		};

		std::string factorial_scheme[10] = {
			"[gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]!",
			"[gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]!",
			"[gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]!",
			"[gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]!",
			"[gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]!",
			"[gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]!",
			"[gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]!",
			"[gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]!",
			"[gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]!",
			"[gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]! [gspm] [gn1]!",
		};

		std::string brackets_factorial_scheme[10] = {
			"((([gn1]! [gspm] [gn1]!) [gspm] ([gn1]! [gspm] [gn1]!)) [gspm] [gn1]!)",
			"(((([gn1]! [gspm] [gn1]!) [gspm] ([gn1]! [gspm] [gn1]!)) [gspm] [gn1]!) [gspm] [gn1]!)",
			"((((([gn1]! [gspm] [gn1]!) [gspm] ([gn1]! [gspm] [gn1]!)) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!)",
			"(((((([gn1]! [gspm] [gn1]!) [gspm] ([gn1]! [gspm] [gn1]!)) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!)",
			"((((((([gn1]! [gspm] [gn1]!) [gspm] ([gn1]! [gspm] [gn1]!)) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!)",
			"(((((((([gn1]! [gspm] [gn1]!) [gspm] ([gn1]! [gspm] [gn1]!)) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!)",
			"((((((((([gn1]! [gspm] [gn1]!) [gspm] ([gn1]! [gspm] [gn1]!)) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!)",
			"(((((((((([gn1]! [gspm] [gn1]!) [gspm] ([gn1]! [gspm] [gn1]!)) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!)",
			"((((((((((([gn1]! [gspm] [gn1]!) [gspm] ([gn1]! [gspm] [gn1]!)) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!)",
			"(((((((((((([gn1]! [gspm] [gn1]!) [gspm] ([gn1]! [gspm] [gn1]!)) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!) [gspm] [gn1]!)",
		};

		std::string factorial_var_scheme[10] = {
			"[gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]!",
			"[gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]!",
			"[gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]!",
			"[gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]!",
			"[gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]!",
			"[gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]!",
			"[gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]!",
			"[gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]!",
			"[gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]!",
			"[gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]! [gspm] [gv]!",
		};

		std::string brackets_factorial_var_scheme[10] = {
			"((([gv]! [gspm] [gv]!) [gspm] ([gv]! [gspm] [gv]!)) [gspm] [gv]!)",
			"(((([gv]! [gspm] [gv]!) [gspm] ([gv]! [gspm] [gv]!)) [gspm] [gv]!) [gspm] [gv]!)",
			"((((([gv]! [gspm] [gv]!) [gspm] ([gv]! [gspm] [gv]!)) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!)",
			"(((((([gv]! [gspm] [gv]!) [gspm] ([gv]! [gspm] [gv]!)) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!)",
			"((((((([gv]! [gspm] [gv]!) [gspm] ([gv]! [gspm] [gv]!)) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!)",
			"(((((((([gv]! [gspm] [gv]!) [gspm] ([gv]! [gspm] [gv]!)) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!)",
			"((((((((([gv]! [gspm] [gv]!) [gspm] ([gv]! [gspm] [gv]!)) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!)",
			"(((((((((([gv]! [gspm] [gv]!) [gspm] ([gv]! [gspm] [gv]!)) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!)",
			"((((((((((([gv]! [gspm] [gv]!) [gspm] ([gv]! [gspm] [gv]!)) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!)",
			"(((((((((((([gv]! [gspm] [gv]!) [gspm] ([gv]! [gspm] [gv]!)) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!) [gspm] [gv]!)",
		};

		std::string functions_in_row_scheme[10] = {
			"[gfo]([gn1]) [gspm] [gfo]([gn1]) [gspm] [gfo]([gn1]) [gspm] [gfo]([gn1]) [gspm] [gfo]([gn1])",
			"[gfo]([gn1]) [gspm] [gfo]([gn1]) [gspm] [gfo]([gn1]) [gspm] [gfo]([gn1]) [gspm] [gfo]([gn1]) [gspm] [gfo]([gn1])",
			"[gfo]([gn1]) [gspm] [gfo]([gn1]) [gspm] [gfo]([gn1]) [gspm] [gfo]([gn1]) [gspm] [gfo]([gn1]) [gspm] [gfo]([gn1]) [gspm] [gfo]([gn1])",
			"[gfo]([gn1]) [gspm] [gfo]([gn1]) [gspm] [gfo]([gn1]) [gspm] [gfo]([gn1]) [gspm] [gfo]([gn1]) [gspm] [gfo]([gn1]) [gspm] [gfo]([gn1]) [gspm] [gfo]([gn1])",
			"[gfo]([gn1]) [gspm] [gfo]([gn1]) [gspm] [gfo]([gn1]) [gspm] [gfo]([gn1]) [gspm] [gfo]([gn1]) [gspm] [gfo]([gn1]) [gspm] [gfo]([gn1]) [gspm] [gfo]([gn1]) [gspm] [gfo]([gn1])",
			"[gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1])",
			"[gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1])",
			"[gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1])",
			"[gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1])",
			"[gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1]) [gspm] [gfo]([gfn1])",
		};

		std::string functions_brackets_in_row_scheme[10] = {
			"(([gfo]([gn1]) [gspm] [gfo]([gn1])) [gspm] ([gfo]([gn1]) [gspm] [gfo]([gn1])) [gspm] [gfo]([gn1]))",
			"((([gfo]([gn1]) [gspm] [gfo]([gn1])) [gspm] ([gfo]([gn1]) [gspm] [gfo]([gn1])) [gspm] [gfo]([gn1])) [gspm] [gfo]([gn1]))",
			"(((([gfo]([gn1]) [gspm] [gfo]([gn1])) [gspm] ([gfo]([gn1]) [gspm] [gfo]([gn1])) [gspm] [gfo]([gn1])) [gspm] [gfo]([gn1])) [gspm] [gfo]([gn1]))",
			"((((([gfo]([gn1])[gspm][gfo]([gn1]))[gspm]([gfo]([gn1])[gspm][gfo]([gn1]))[gspm][gfo]([gn1]))[gspm][gfo]([gn1]))[gspm][gfo]([gn1]))[gspm][gfo]([gn1]))",
			"(((((([gfo]([gn1]) [gspm] [gfo]([gn1])) [gspm] ([gfo]([gn1]) [gspm] [gfo]([gn1])) [gspm] [gfo]([gn1])) [gspm] [gfo]([gn1])) [gspm] [gfo]([gn1])) [gspm] [gfo]([gn1])) [gspm] [gfo]([gn1]))",
			"(([gfo]([gfn1]) [gspm] [gfo]([gfn1])) [gspm] ([gfo]([gfn1]) [gspm] [gfo]([gfn1])) [gspm] ([gfo]([gfn1]) [gspm] [gfo]([gfn1])) [gspm] ([gfo]([gfn1]) [gspm] [gfo]([gfn1])) [gspm] [gfo]([gfn1]))",
			"((([gfo]([gfn1]) [gspm] [gfo]([gfn1])) [gspm] ([gfo]([gfn1]) [gspm] [gfo]([gfn1])) [gspm] ([gfo]([gfn1]) [gspm] [gfo]([gfn1])) [gspm] ([gfo]([gfn1]) [gspm] [gfo]([gfn1])) [gspm] [gfo]([gfn1])) [gspm] [gfo]([gfn1]))",
			"(((([gfo]([gfn1]) [gspm] [gfo]([gfn1])) [gspm] ([gfo]([gfn1]) [gspm] [gfo]([gfn1])) [gspm] ([gfo]([gfn1]) [gspm] [gfo]([gfn1])) [gspm] ([gfo]([gfn1]) [gspm] [gfo]([gfn1])) [gspm] [gfo]([gfn1])) [gspm] [gfo]([gfn1])) [gspm] [gfo]([gfn1]))",
			"((((([gfo]([gfn1]) [gspm] [gfo]([gfn1])) [gspm] ([gfo]([gfn1]) [gspm] [gfo]([gfn1])) [gspm] ([gfo]([gfn1]) [gspm] [gfo]([gfn1])) [gspm] ([gfo]([gfn1]) [gspm] [gfo]([gfn1])) [gspm] [gfo]([gfn1])) [gspm] [gfo]([gfn1])) [gspm] [gfo]([gfn1])) [gspm] [gfo]([gfn1]))",
			"(((((([gfo]([gfn1]) [gspm] [gfo]([gfn1])) [gspm] ([gfo]([gfn1]) [gspm] [gfo]([gfn1])) [gspm] ([gfo]([gfn1]) [gspm] [gfo]([gfn1])) [gspm] ([gfo]([gfn1]) [gspm] [gfo]([gfn1])) [gspm] [gfo]([gfn1])) [gspm] [gfo]([gfn1])) [gspm] [gfo]([gfn1])) [gspm] [gfo]([gfn1])) [gspm] [gfo]([gfn1]))",
		};

		std::string functions_in_row_var_scheme[10] = {
			"[gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv])",
			"[gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv])",
			"[gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv])",
			"[gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv])",
			"[gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv])",
			"[gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv])",
			"[gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv])",
			"[gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv])",
			"[gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv])",
			"[gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv])",
		};

		std::string functions_brackets_in_row_var_scheme[10] = {
			"(([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] [gfo]([gv]))",
			"((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] [gfo]([gv])) [gspm] [gfo]([gv]))",
			"(((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] [gfo]([gv])) [gspm] [gfo]([gv])) [gspm] [gfo]([gv]))",
			"((((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] [gfo]([gv])) [gspm] [gfo]([gv])) [gspm] [gfo]([gv])) [gspm] [gfo]([gv]))",
			"(((((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] [gfo]([gv])) [gspm] [gfo]([gv])) [gspm] [gfo]([gv])) [gspm] [gfo]([gv])) [gspm] [gfo]([gv]))",
			"(([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] [gfo]([gv]))",
			"((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] [gfo]([gv])) [gspm] [gfo]([gv]))",
			"(((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] [gfo]([gv])) [gspm] [gfo]([gv])) [gspm] [gfo]([gv]))",
			"((((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] [gfo]([gv])) [gspm] [gfo]([gv])) [gspm] [gfo]([gv])) [gspm] [gfo]([gv]))",
			"(((((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] [gfo]([gv])) [gspm] [gfo]([gv])) [gspm] [gfo]([gv])) [gspm] [gfo]([gv])) [gspm] [gfo]([gv]))",
		};

		std::string more_collections_of_functions_scheme[10] = {
			"[gf]([gn1]) [gspm] [gf]([gn1]) [gspm] [gf]([gn1]) [gspm] [gf]([gn1]) [gspm] [gf]([gn1])",
			"[gf]([gn1]) [gspm] [gf]([gn1]) [gspm] [gf]([gn1]) [gspm] [gf]([gn1]) [gspm] [gf]([gn1]) [gspm] [gf]([gn1])",
			"[gf]([gn1]) [gspm] [gf]([gn1]) [gspm] [gf]([gn1]) [gspm] [gf]([gn1]) [gspm] [gf]([gn1]) [gspm] [gf]([gn1]) [gspm] [gf]([gn1])",
			"[gf]([gn1]) [gspm] [gf]([gn1]) [gspm] [gf]([gn1]) [gspm] [gf]([gn1]) [gspm] [gf]([gn1]) [gspm] [gf]([gn1]) [gspm] [gf]([gn1]) [gspm] [gf]([gn1])",
			"[gf]([gn1]) [gspm] [gf]([gn1]) [gspm] [gf]([gn1]) [gspm] [gf]([gn1]) [gspm] [gf]([gn1]) [gspm] [gf]([gn1]) [gspm] [gf]([gn1]) [gspm] [gf]([gn1]) [gspm] [gf]([gn1])",
			"[gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1])",
			"[gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1])",
			"[gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1])",
			"[gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1])",
			"[gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1]) [gspm] [gf]([gfn1])",
		};

		std::string more_collections_of_functions_brackets_scheme[10] = {
			"(([gf]([gn1]) [gspm] [gf]([gn1])) [gspm] ([gf]([gn1]) [gspm] [gf]([gn1])) [gspm] [gf]([gn1]))",
			"((([gf]([gn1]) [gspm] [gf]([gn1])) [gspm] ([gf]([gn1]) [gspm] [gf]([gn1])) [gspm] [gf]([gn1])) [gspm] [gf]([gn1]))",
			"(((([gf]([gn1]) [gspm] [gf]([gn1])) [gspm] ([gf]([gn1]) [gspm] [gf]([gn1])) [gspm] [gf]([gn1])) [gspm] [gf]([gn1])) [gspm] [gf]([gn1]))",
			"((((([gf]([gn1]) [gspm] [gf]([gn1])) [gspm] ([gf]([gn1]) [gspm] [gf]([gn1])) [gspm] [gf]([gn1])) [gspm] [gf]([gn1])) [gspm] [gf]([gn1])) [gspm] [gf]([gn1]))",
			"(((((([gf]([gn1]) [gspm] [gf]([gn1])) [gspm] ([gf]([gn1]) [gspm] [gf]([gn1])) [gspm] [gf]([gn1])) [gspm] [gf]([gn1])) [gspm] [gf]([gn1])) [gspm] [gf]([gn1])) [gspm] [gf]([gn1]))",
			"(([gf]([gfn1]) [gspm] [gf]([gfn1])) [gspm] ([gf]([gfn1]) [gspm] [gf]([gfn1])) [gspm] ([gf]([gfn1]) [gspm] [gf]([gfn1])) [gspm] ([gf]([gfn1]) [gspm] [gf]([gfn1])) [gspm] [gf]([gfn1]))",
			"((([gf]([gfn1]) [gspm] [gf]([gfn1])) [gspm] ([gf]([gfn1]) [gspm] [gf]([gfn1])) [gspm] ([gf]([gfn1]) [gspm] [gf]([gfn1])) [gspm] ([gf]([gfn1]) [gspm] [gf]([gfn1])) [gspm] [gf]([gfn1])) [gspm] [gf]([gfn1]))",
			"(((([gf]([gfn1]) [gspm] [gf]([gfn1])) [gspm] ([gf]([gfn1]) [gspm] [gf]([gfn1])) [gspm] ([gf]([gfn1]) [gspm] [gf]([gfn1])) [gspm] ([gf]([gfn1]) [gspm] [gf]([gfn1])) [gspm] [gf]([gfn1])) [gspm] [gf]([gfn1])) [gspm] [gf]([gfn1]))",
			"((((([gf]([gfn1]) [gspm] [gf]([gfn1])) [gspm] ([gf]([gfn1]) [gspm] [gf]([gfn1])) [gspm] ([gf]([gfn1]) [gspm] [gf]([gfn1])) [gspm] ([gf]([gfn1]) [gspm] [gf]([gfn1])) [gspm] [gf]([gfn1])) [gspm] [gf]([gfn1])) [gspm] [gf]([gfn1])) [gspm] [gf]([gfn1]))",
			"(((((([gf]([gfn1]) [gspm] [gf]([gfn1])) [gspm] ([gf]([gfn1]) [gspm] [gf]([gfn1])) [gspm] ([gf]([gfn1]) [gspm] [gf]([gfn1])) [gspm] ([gf]([gfn1]) [gspm] [gf]([gfn1])) [gspm] [gf]([gfn1])) [gspm] [gf]([gfn1])) [gspm] [gf]([gfn1])) [gspm] [gf]([gfn1])) [gspm] [gf]([gfn1]))",
		};

		std::string more_collections_of_functions_var_scheme[10] = {
			"[gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv])",
			"[gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv])",
			"[gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv])",
			"[gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv])",
			"[gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv])",
			"[gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv])",
			"[gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv])",
			"[gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv])",
			"[gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv])",
			"[gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv])",
		};

		std::string more_collections_of_functions_var_brackets_scheme[10] = {
			"(([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv])) [gspm] [gf]([gv]))",
			"((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv])) [gspm] [gf]([gv])) [gspm] [gf]([gv]))",
			"(((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv])) [gspm] [gf]([gv])) [gspm] [gf]([gv])) [gspm] [gf]([gv]))",
			"((((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv])) [gspm] [gf]([gv])) [gspm] [gf]([gv])) [gspm] [gf]([gv])) [gspm] [gf]([gv]))",
			"(((((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv])) [gspm] [gf]([gv])) [gspm] [gf]([gv])) [gspm] [gf]([gv])) [gspm] [gf]([gv])) [gspm] [gf]([gv]))",
			"(([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv])) [gspm] [gf]([gv]))",
			"((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv])) [gspm] [gf]([gv])) [gspm] [gf]([gv]))",
			"(((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv])) [gspm] [gf]([gv])) [gspm] [gf]([gv])) [gspm] [gf]([gv]))",
			"((((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv])) [gspm] [gf]([gv])) [gspm] [gf]([gv])) [gspm] [gf]([gv])) [gspm] [gf]([gv]))",
			"(((((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv])) [gspm] [gf]([gv])) [gspm] [gf]([gv])) [gspm] [gf]([gv])) [gspm] [gf]([gv])) [gspm] [gf]([gv]))",
		};

		std::string unrealistic_more_replacement_var_scheme[5] = {
			"[gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv]",
			"[gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv]",
			"[gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv]",
			"[gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv]",
			"[gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv] [gspm] [gv]",
		};

		std::string unrealistic_more_replacement_var_brackets_scheme[5] = {
			"((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv]))",
			"(((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv])) [gspm] ((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv])))",
			"((((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv])) [gspm] ((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv]))) [gspm] (((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv])) [gspm] ((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv]))))",
			"(((((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv])) [gspm] ((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv]))) [gspm] (((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv])) [gspm] ((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv])))) [gspm] ((((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv])) [gspm] ((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv]))) [gspm] (((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv])) [gspm] ((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv])))))",
			"((((((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv])) [gspm] ((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv]))) [gspm] (((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv])) [gspm] ((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv])))) [gspm] ((((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv])) [gspm] ((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv]))) [gspm] (((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv])) [gspm] ((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv]))))) [gspm] (((((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv])) [gspm] ((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv]))) [gspm] (((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv])) [gspm] ((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv])))) [gspm] ((((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv])) [gspm] ((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv]))) [gspm] (((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv])) [gspm] ((([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] (([gv] [gspm] [gv]) [gspm] ([gv] [gspm] [gv])) [gspm] ([gv] [gspm] [gv]))))))",
		};

		std::string unrealistic_more_replacement_var_in_functions_in_row_scheme[5] = {
			"[gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv])",
			"[gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv])",
			"[gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv])",
			"[gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv])",
			"[gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv]) [gspm] [gfo]([gv])",
		};

		std::string unrealistic_more_replacement_var_in_functions_in_row_brackets_scheme[5] = {
			"((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])))",
			"(((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))))",
			"((((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])))) [gspm] (((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])))))",
			"(((((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])))) [gspm] (((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))))) [gspm] ((((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])))) [gspm] (((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))))))",
			"((((((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])))) [gspm] (((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))))) [gspm] ((((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])))) [gspm] (((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])))))) [gspm] (((((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])))) [gspm] (((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))))) [gspm] ((((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])))) [gspm] (((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ((([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] (([gfo]([gv]) [gspm] [gfo]([gv])) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv]))) [gspm] ([gfo]([gv]) [gspm] [gfo]([gv])))))))",
		};

		std::string unrealistic_more_replacement_var_in_more_collections_functions_scheme[5] = {
			"[gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv])",
			"[gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv])",
			"[gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv])",
			"[gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv])",
			"[gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv]) [gspm] [gf]([gv])",
		};

		std::string unrealistic_more_replacement_var_in_more_collections_functions_brackets_scheme[5] = {
			"((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv])))",
			"(((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))))",
			"((((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv])))) [gspm] (((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv])))))",
			"(((((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv])))) [gspm] (((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))))) [gspm] ((((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv])))) [gspm] (((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))))))",
			"((((((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv])))) [gspm] (((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))))) [gspm] ((((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv])))) [gspm] (((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv])))))) [gspm] (((((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv])))) [gspm] (((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))))) [gspm] ((((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv])))) [gspm] (((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ((([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] (([gf]([gv]) [gspm] [gf]([gv])) [gspm] ([gf]([gv]) [gspm] [gf]([gv]))) [gspm] ([gf]([gv]) [gspm] [gf]([gv])))))))",
		};

		std::vector<std::string*> mass_schemes = {
			plus_minus_scheme, // +
			plus_minus_brackets_scheme, // +
			plus_minus_var_scheme, // +
			plus_minus_brackets_var_scheme, // +
			multiply_devide_scheme, // +
			multiply_brackets_devide_scheme, // +
			multiply_devide_var_scheme, // +
			multiply_brackets_devide_var_scheme, // +
			factorial_scheme, // +
			brackets_factorial_scheme, // +
			factorial_var_scheme, // +
			brackets_factorial_var_scheme, // +
			functions_in_row_scheme, // + 
			functions_brackets_in_row_scheme, // +
			functions_in_row_var_scheme, // +
			functions_brackets_in_row_var_scheme, // +
			more_collections_of_functions_scheme, // +
			more_collections_of_functions_brackets_scheme, // +
			more_collections_of_functions_var_scheme, // +
			more_collections_of_functions_var_brackets_scheme, // +
			unrealistic_more_replacement_var_scheme, // +
			unrealistic_more_replacement_var_brackets_scheme, // +
			unrealistic_more_replacement_var_in_functions_in_row_scheme, // +
			unrealistic_more_replacement_var_in_functions_in_row_brackets_scheme, // +
			unrealistic_more_replacement_var_in_more_collections_functions_scheme, // +
			unrealistic_more_replacement_var_in_more_collections_functions_brackets_scheme // +
		};

		void Generate() {
			once_func = GenerateRandomFunction();
			int size_first = 10;
			int size_second = 5;
			int size_all_schemes = Bench::all_benchs.size();
			for (int i = 0; i < size_all_schemes; i++) {
				XE::Bench::all_benchs[i].clear();
			}
			for (int i = 0; i < size_all_schemes; i++) {
				if (i < 20) {
					for (int g = 0; g < size_first; g++) {
						for (int k = 0; k < 5000; k++) {
							XE::Bench::all_benchs[i].push_back(GenerateExpr(mass_schemes[i][g]));
						}
					}
				}
				else {
					for (int j = 0; j < size_second; j++) {
						for (int k = 0; k < 0; k++) {
							XE::Bench::all_benchs[i].push_back(GenerateExpr(mass_schemes[i][j]));
						}
					}
				}
			}
		}
	}
}

