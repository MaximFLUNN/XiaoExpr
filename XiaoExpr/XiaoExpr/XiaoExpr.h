#pragma once

//#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <math.h>
#pragma region Defines

#define OPEN_BRACKET 40
#define CLOSE_BRACKET 41
#define COMMA 44
#define PLUS 43
#define MINUS 45
#define MULTIPLY 42
#define DEVIDE 47
#define EXPONINTEALE 94
#define FACTORIAL 33
#define DOT 46
#define SPACE 32
#define START_NUMBERS 48
#define END_NUMBERS 57
#define START_UPPERCASE_LETTER 65
#define END_UPPERCASE_LETTER 90
#define START_LOWERCASE_LETTER 97
#define END_LOWERCASE_LETTER 122
#define FUNCTION_OFFSET 200
#define XE_PI 3.1415926535897931

#pragma endregion

// [EN] Namespace XiaoExpr 
// [RU] Пространство имён XiaoExpr
namespace XE {//XiaoExpr {

	int str_to_int(std::string _str) {
		int tmp_value = 0;
		bool minus = false;
		int size = _str.size();
		for (unsigned int i = 0; i < size; i++) {
			char s = _str[i];
			s == '-' ? minus = true : tmp_value = (tmp_value * 10) + (static_cast<unsigned int>(s) - START_NUMBERS);
		}
		minus ? tmp_value *= -1 : NULL;
		return tmp_value;
	}

	double str_to_double(std::string _str) {
		double value = 0;
		double next = 0.1;
		double correct = 1;
		bool dot = false;
		bool minus = false;
		int size = _str.size();
		int count = 0;
		for (unsigned int i = 0, arrIndex = 0; i < size; i++) {
			char s = _str[i];
			s == '-' ? minus = true
				: s == '.' ? dot = true
				: dot ? correct *= next, value += ((static_cast<unsigned int>(s) - START_NUMBERS) * correct)
				: value = (value * 10) + (static_cast<unsigned int>(s) - START_NUMBERS);
		}
		minus ? value *= -1 : NULL;
		return value;
	}

	// [EN] Sample custom function
	// [RU] Шаблон пользовательской функции
	typedef double(*CustomFunc) (std::stack<double>&);

	namespace funcs_lib {

		double _abs(std::stack<double>& content) {
			return abs(content.top());
		}

		double _ceil(std::stack<double>& content) {
			return ceil(content.top());
		}

		double _floor(std::stack<double>& content) {
			return floor(content.top());
		}

		double _cos(std::stack<double>& content) {
			return cos(content.top());
		}

		double _sin(std::stack<double>& content) {
			return sin(content.top());
		}

		double _tan(std::stack<double>& content) {
			return tan(content.top());
		}

		double _log(std::stack<double>& content) {
			return log10(content.top());
		}

		/*double _log10(std::stack<double>& content) {
			return log10(content.top());
		}*/

		double _sqrt(std::stack<double>& content) {
			return sqrt(content.top());
		}

		/*double _acos(std::stack<double>& content) {
			return acos(content.top());
		}*/

		/*double _asin(std::stack<double>& content) {
			return asin(content.top());
		}*/

		double _atan2(std::stack<double>& content) {
			double first;
			double second;
			first = content.top();
			content.pop();
			second = content.top();
			return atan2(first, second);
		}

		/*double _cosh(std::stack<double>& content) {
			return cosh(content.top());
		}

		double _sinh(std::stack<double>& content) {
			return sinh(content.top());
		}*/
	}

	// [EN] Namespace add in XiaoExpr 
	// [RU] Пространство имён add в XiaoExpr
	namespace add {
		// [EN] Add variable
		// [RU] Добавление переменной
		void var(std::pair<char, double> variable);
		void vars(std::vector<std::pair<char, double>> variables);

		// [EN] Add function
		// [RU] Добавление функции
		void func(std::pair<std::string, CustomFunc> function);
		void funcs(std::vector<std::pair<std::string, CustomFunc>> function);
	}

	// [EN] Namespace del in XiaoExpr 
	// [RU] Пространство имён del в XiaoExpr
	namespace del {
		/// <summary>
		/// <para>[EN] Del variable</para>
		/// [RU] Удаление переменной
		/// </summary>
		void var(char name);
		void vars(std::vector<char> names);

		/// <summary>
		/// <para>[EN] Del function</para>
		/// [RU] Удаление функции
		/// </summary>
		void func(std::string name);
		void funcs(std::vector<std::string> names);
	}

	void load_default_functions_library();

	// [EN] Functions in XiaoExpr 
	// [RU] Переменные в XiaoExpr
	std::pair<char, double> last_used_var;
	std::vector<std::pair<char, double>> XiaoVars;

	// [EN] Functions in XiaoExpr 
	// [RU] Функции в XiaoExpr
	std::pair<std::string, int> last_used_func;
	std::vector<std::pair<std::string, CustomFunc>> XiaoFuncs;

	// [EN] Sign in XiaoExpr 
	// [RU] Специальные символы в XiaoExpr
	std::vector<char> SignAlphabet{
		'+', '-', '*', 
		'/', '^', '!',
		','
	};

	// [EN] Class Solver for Expression
	// [RU] Класс Solver для выражений
	class Solver {
	private:
		int current_element;
		int actions_top;
		int current_priority;
		int last_priority;
		double first_num;
		double second_num;
		double last_answer;
		unsigned int expr_size;
		std::string word;
		std::stack<double> stack_for_function;
		std::stack<double> numbers;
		std::stack<int> actions;
		bool last_close_bracket;
		bool last_factorial_action;

		int get_func_id(std::string name);
		void stacks_action_evaluate();
		void stacks_calculate();
		int calculate_priority(char action); 
		void clear_stack(std::stack<double>& stack);

	public:
		// [EN] Solver default constructor
		// [RU] Конструктор по умолчанию для Solver 
		Solver();
		
		// [EN] Expression calculate
		// [RU] Вычисление выражения
		double calculate(std::string expr);

		double call_func(int id, std::stack<double> &content);
		double get_value_var(char name);

		/// <summary>
		/// <para>[EN] Solver destructor</para>
		/// <para>[RU] Деструктор для Solver</para>
		/// </summary>
		~Solver();
	};

#pragma region Realization

	Solver::Solver():
		expr_size(NULL), 
		word(""), 
		current_element(NULL),
		actions_top(NULL),
		first_num(NULL),
		second_num(NULL),
		current_priority(NULL),
		last_priority(NULL),
		last_answer(NULL), 
		last_close_bracket(NULL), 
		last_factorial_action(NULL) {}

	Solver::~Solver() {}

	double Solver::calculate(std::string expr) {
		expr_size = expr.size();
		word = "";
		current_element = ' ';
		for (unsigned int i = NULL; i <= expr_size; i++) {
			// текущий элемент
			current_element = expr[i];
			// пропускаем пробелы
			if (current_element == SPACE) {
				continue;
			}
			// если текущий элемент цифра или буква
			else if (current_element >= START_UPPERCASE_LETTER && current_element <= END_UPPERCASE_LETTER 
				|| current_element >= START_LOWERCASE_LETTER && current_element <= END_LOWERCASE_LETTER 
				|| current_element >= START_NUMBERS && current_element <= END_NUMBERS 
				|| current_element == DOT) {
				word += current_element;
				continue;
			}
			// если знак 
			else {
				// чила запятые переменные (запись) | знаки функции (вычисление)
				char first_char = word[NULL];
				int word_size = word.size();
				bool word_complete = false;
				// проверка word на число
				if (first_char >= START_NUMBERS && first_char <= END_NUMBERS) {
					numbers.push(str_to_double(word));
					word.clear();
					word_complete = true;
				}
				// проверка word на переменную
				if (word_size == 1 && !word_complete 
					&& ((first_char >= START_LOWERCASE_LETTER 
					&& first_char <= END_LOWERCASE_LETTER)
					|| (first_char >= START_UPPERCASE_LETTER
					&& first_char <= END_UPPERCASE_LETTER))) {
					numbers.push(get_value_var(first_char));
					word.clear();
					word_complete = true;
				}
				// проверка word на функцию
				if (word_size > 1 && !word_complete) {
					char temp = current_element;
					current_element = get_func_id(word);
					word.clear();
					word_complete = true;
					// проверка стека с операциями + вычисление
					stacks_action_evaluate();
					current_element = temp;
				}
				// если это открывающаяся скобка добавить и приступить к следующей итерации
				if (current_element == OPEN_BRACKET) {
					actions.push(OPEN_BRACKET);
					continue;
				}
				// проверка current_element на знак
				for (const auto& elem : XE::SignAlphabet) {
					if (current_element == elem) {
						if (current_element == FACTORIAL) {
							last_factorial_action = true;
							double temp_value = ++(numbers.top());
							numbers.pop();
							numbers.push(tgamma(temp_value));
							break;
						}
						else if (current_element == COMMA) {
							actions.push(COMMA);
							last_factorial_action = false;
							break;
						}
						else if ((current_element == MINUS 
							&& word.empty()
							&& !word_complete) 
							&& !last_close_bracket
							&& !last_factorial_action) 
						{
							numbers.push(NULL);
							stacks_action_evaluate();
							last_factorial_action = false;
							break;
						}
						else {
							// проверка стека с операциями + вычисление
							stacks_action_evaluate();
							last_factorial_action = false;
							break;
						}
					}
				}
				if (current_element == CLOSE_BRACKET) {
					last_close_bracket = true;
					stacks_action_evaluate();
				}
				else {
					last_close_bracket = false;
				}
			}
		}
		current_element = NULL;
		stacks_action_evaluate();
		last_answer = numbers.top();
		clear_stack(numbers);
		return last_answer;
	}

	void Solver::stacks_action_evaluate() { 
		bool until_open_bracket = (current_element == CLOSE_BRACKET ? true : false);
		bool to_end = current_element == NULL;
		bool until_down_sign = !(until_open_bracket || to_end);
		current_priority = calculate_priority(current_element);
		while (until_down_sign) {
			actions_top = (!actions.empty() ? actions.top() : PLUS);
			last_priority = calculate_priority(actions_top);
			if (!current_element) {
				break;
			}
			if (current_priority > last_priority || actions.empty() || actions_top == OPEN_BRACKET) {
				actions.push(current_element);
				current_element = NULL;
			}
			else {
				stacks_calculate();
			}
		}
		while (until_open_bracket) {
			actions_top = (!actions.empty() ? actions.top() : PLUS);
			if (actions_top != OPEN_BRACKET) {
				stacks_calculate();
			}
			else {
				actions.pop();
				break;
			}
		}
		while (to_end) {
			if (!actions.empty()) {
				stacks_calculate();
			}
			else {
				break;
			}
		}
	}

	void Solver::stacks_calculate() {
		actions_top = actions.top();
		actions.pop();
		first_num = numbers.top();
		numbers.pop();
		if (!numbers.empty() && actions_top != COMMA && actions_top < FUNCTION_OFFSET) {
			second_num = numbers.top();
			numbers.pop();
		}
		if (actions_top >= FUNCTION_OFFSET) {
			stack_for_function.push(first_num);
		}
		if (actions_top != COMMA) {
			numbers.push(
				actions_top == PLUS ? (second_num + first_num) :
				actions_top == MINUS ? (second_num - first_num) :
				actions_top == MULTIPLY ? (second_num * first_num) :
				actions_top == DEVIDE ? (second_num / first_num) :
				actions_top == EXPONINTEALE ? (pow(second_num, first_num)) : 
				call_func(actions_top, stack_for_function)
			);
			if (actions_top >= FUNCTION_OFFSET) {
				clear_stack(stack_for_function);
			}
		}
		else {
			stack_for_function.push(first_num);
		}
	}

	int Solver::calculate_priority(char action) {
		return (
			action == PLUS || action == MINUS ? 1 : 
			action == MULTIPLY || action == DEVIDE ? 2 :
			action == EXPONINTEALE ? 3 : 4
			);
	}

	void Solver::clear_stack(std::stack<double> &stack) {
		while (!stack.empty()) {
			stack.pop();
		}
	}

	double Solver::get_value_var(char name) {
		if (last_used_var.first == name) {
			return last_used_var.second;
		}
		for (const auto& elem : XiaoVars) {
			if (elem.first == name) {
				if (last_used_var.first != name) {
					last_used_var = { name, elem.second };
				}
				return elem.second;
			}
		}
		return 0;
	}

	int Solver::get_func_id(std::string name) {
		if (last_used_func.first == name) {
			return last_used_func.second;
		}
		int size = XiaoFuncs.size();
		for (int i = NULL; i < size; i++) {
			if (XiaoFuncs[i].first == name) {
				if (last_used_func.first != name) {
					last_used_func = { name, i + FUNCTION_OFFSET };
				}
				return i + FUNCTION_OFFSET;
			}
		}
		return NULL;
	}

	double Solver::call_func(int id, std::stack<double> &content) {
		return XiaoFuncs[id - FUNCTION_OFFSET].second(content);
	}
	
	void XE::add::var(std::pair<char, double> variable) {
		for (auto& elem : XE::XiaoVars) {
			if (elem.first == variable.first) {
				elem.second = variable.second;
				return;
			}
		}
		XE::XiaoVars.push_back(variable);
	}

	void XE::add::vars(std::vector<std::pair<char, double>> vars) {
		for (auto& elem : vars) {
			XE::add::var(elem);
		}
	}

	void XE::add::func(std::pair<std::string, CustomFunc> function) {
		for (auto& elem : XE::XiaoFuncs) {
			if (elem.first == function.first) {
				elem.second = function.second;
				return;
			}
		}
		XE::XiaoFuncs.push_back(function);
	}

	void XE::add::funcs(std::vector<std::pair<std::string, CustomFunc>> functions) {
		for (auto& elem : functions) {
			XE::add::func(elem);
		}
	}

	void XE::del::var(char name) {
		for (auto iterator = XE::XiaoVars.begin(); iterator != XE::XiaoVars.end(); iterator++) {
			if ((*iterator).first == name) {
				XE::XiaoVars.erase(iterator);
				return;
			}
		}
	}

	void XE::del::vars(std::vector<char> names) {
		for (auto& elem : names) {
			XE::del::var(elem);
		}
	}

	void XE::del::func(std::string name) {
		for (auto iterator = XE::XiaoFuncs.begin(); iterator != XE::XiaoFuncs.end(); iterator++) {
			if ((*iterator).first == name) {
				XE::XiaoFuncs.erase(iterator);
				return;
			}
		}
	}

	void XE::del::funcs(std::vector<std::string> names) {
		for (auto& elem : names) {
			XE::del::func(elem);
		}
	}

	void load_default_functions_library() {
		XE::add::func({ "abs", XE::funcs_lib::_abs });
		XE::add::func({ "ceil", XE::funcs_lib::_ceil });
		XE::add::func({ "floor", XE::funcs_lib::_floor });
		XE::add::func({ "cos", XE::funcs_lib::_cos });
		XE::add::func({ "sin", XE::funcs_lib::_sin });
		XE::add::func({ "tan", XE::funcs_lib::_tan });
		XE::add::func({ "log", XE::funcs_lib::_log });
		XE::add::func({ "sqrt", XE::funcs_lib::_sqrt });
		//XE::add::func({ "log10", XE::funcs_lib::_log10 });
		//XE::add::func({ "acos", XE::funcs_lib::_acos });
		//XE::add::func({ "asin", XE::funcs_lib::_asin });
		//XE::add::func({ "sinh", XE::funcs_lib::_sinh });
		//XE::add::func({ "cosh", XE::funcs_lib::_cosh });
	}
}

#pragma endregion