#include "XiaoExpr.h"
#include <ctime>
#include <string>
#include "XiaoBench.h"
#include "tinyexpr.h"
#include "Color.h"

double f1(std::stack<double> &content) {
	return 123;
}

double add(std::stack<double> &content) {
	double value = 0;
	while (!content.empty()) {
		value += content.top();
		content.pop();
	}
	return value;
}

std::string fix_fac_for_tinyexpr(std::string str) {
	std::string out = "";
	const char* out_finish;
	int size = str.size();
	for (int i = 0; i < size; i++) {
		if (str[i] == '!') {
			out[out.size() - 1] = 'f';
			out += "ac(";
			out += str[i - 1];
			out += ')';
		}
		else {
			out += str[i];
		}
	}
	//out_finish = out.c_str();
	return out;//out_finish;
}

int main() {
	std::string a;
	a = "123";
	std::cout << a[0] << " | " << a[1] << " | " << a[2] << " | " << a[3];
	char a1 = a[0];
	char a2 = a[1];
	char a3 = a[2];
	char a4 = a[3]; //  \0

	XE::add::var({'a', 2.213});
	XE::add::func({ "f1", f1 });
	auto b = XE::XiaoVars;
	auto c = XE::XiaoFuncs;
	std::stack<double> st_first;
	st_first.push(0);
	std::cout << XE::XiaoFuncs[0].second(st_first);

	auto s = XE::Solver();
	//s.solve("sin( 22 +  ) / 17!");
	int a11 = 0;
	//auto answer = s.read(a11);
	//std::cout << "\noperand: ( " << answer.first << " ) | operator ( " << answer.second << " )";
	//answer = s.read(a11);
	//std::cout << "\noperand: ( " << answer.first << " ) | operator ( " << answer.second << " )";

	std::cout.precision(10);
	////////////////////////////////////
	std::cout << "\n\n|/int test\\|\n";
	////////////////////////////////////
	int example_int = -122;
	std::string expample_str = "-122";
	unsigned int start_time = clock();
	for (int i = 0; i < 100; i++) {
		XE::str_to_int("-122999");
	}
	unsigned int end_time = clock();
	std::cout << "\n" << end_time - start_time << "ms | my convert: " << XE::str_to_int("-122999");

	start_time = clock();
	for (int i = 0; i < 100; i++) {
		std::stoi("-122999");
	}
	end_time = clock();
	std::cout << "\n" << end_time - start_time << "ms | lib convert: " << std::stoi("-122999");
	////////////////////////////////////
	std::cout << "\n\n|/double test\\|\n";
	////////////////////////////////////
	start_time = clock();
	for (int i = 0; i < 100; i++) {
		XE::str_to_double("-122999.21569");
	}
	end_time = clock();
	std::cout << "\n" << end_time - start_time << "ms | my convert: " << XE::str_to_double("-122999.21569");

	start_time = clock();
	for (int i = 0; i < 100; i++) {
		std::stod("-122999.21569");
	}
	end_time = clock();
	std::cout << "\n" << end_time - start_time << "ms | lib convert: " << std::stod("-122999.21569");

	XE::add::vars({
			{'q', 1}, {'w', 7}, {'e', 2}, {'r', 7},
			{'t', 2.213}, {'y', 2.213}, {'u', 2.213},
			{'i', 2.213}, {'o', 2.213}, {'p', 2.213},
			{'s', 2.213}, {'d', 2.213}, {'f', 2.213},
			{'g', 2.213}, {'h', 2.213}, {'j', 2.213},
			{'k', 2.213}, {'l', 2.213}, {'z', 2.213},
			{'c', 2.213}, {'v', 2.213}, {'b', 3.312},
			{'n', 3.312}, {'m', 3.312}, {'Q', 3.312},
			{'W', 3.312}, {'E', 3.312}, {'R', 3.312},
			{'T', 3.312}, {'Y', 3.312}, {'U', 3.312},
			{'I', 3.312}, {'O', 3.312}, {'P', 3},
			{'A', 3}, {'S', 3}, {'D', 3}, {'F', 3},
			{'G', 3}, {'H', 3}, {'J', 3}, {'K', 3},
			{'L', 3}, {'Z', 3}, {'X', 3}, {'C', 2},
			{'V', 2}, {'B', 2}, {'N', 2}, {'M', 2}
		});

	std::cout << "\n\n\n";
	XE::add::var({'x', 2.213});
	XE::add::func({"add", add});
	XE::load_default_functions_library();
	std::string expression_1 = "2*(2+2)"; // correct
	std::string expression_2 = "6!+4"; // correct
	std::string expression_3 = "2+2*2"; // correct
	std::string expression_4 = "2+2*2*2+2-2^2+3!"; // correct
	std::string expression_5 = "(x+x+x+x+x)*x"; // correct
	std::string expression_6 = "1+add(2, x, add(2, x, 3, 3))"; // correct
	//std::string expression__7 = "(-1)-(-2)-12*(-2)-2-(-4)-(-5!)"; // correct
	//std::string expression__7 = "((tan(2)) + (cos(8) + sin(5)))"; // correct
	//std::string expression__7 = "a + F + k - V - m - x + b - S"; // correct
	//std::string expression__7 = "tan(1) + tan(7) + log(4) - 7 + log(6) - sin(7) - 8 - tan(3) - cos(3)"; // correct
	std::string expression__7 = "cos(7) + tan(6) + log(2) + 5 - log(2) + 4 - log(7) + 7 - sin(8)"; // correct // 
	std::cout << "New CPS! \n";
	std::cout << "1) expr: " << expression_1 << "\n";
	std::cout << "1) answer: " << XE::Solver().calculate(expression_1) << "\n";
	std::cout << "2) expr: " << expression_2 << "\n";
	std::cout << "2) answer: " << XE::Solver().calculate(expression_2) << "\n";
	std::cout << "3) expr: " << expression_3 << "\n";
	std::cout << "3) answer: " << XE::Solver().calculate(expression_3) << "\n";
	std::cout << "4) expr: " << expression_4 << "\n";
	std::cout << "4) answer: " << XE::Solver().calculate(expression_4) << "\n";
	std::cout << "5) expr: " << expression_5 << "\n";
	std::cout << "5) answer: " << XE::Solver().calculate(expression_5) << "\n";
	std::cout << "6) expr: " << expression_6 << "\n";
	std::cout << "6) answer: " << XE::Solver().calculate(expression_6) << "\n";
	std::cout << "7) expr: " << expression__7 << "\n";
	std::cout << "7) answer: " << XE::Solver().calculate(expression__7) << "\n";
	std::cout << "\n\n\n";
	
	volatile double g = 0;
	XE::Solver d;
	std::string expression_7 = "sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(1234567)))))))))))))))))))))))))))))))))))))))))))))))))))";
	//d.load_def_funcs_lib();
	//XE::add::func({ "sqrt", sqrt });
	start_time = clock();
	//d.calculate("");
	for (int i = 0; i < 10000; i++) {
		g += d.calculate(expression_7);
	}
	end_time = clock();
	std::cout << "\n" << end_time - start_time << "ms | lib cps: " << d.calculate(expression_7) << "\n";
	system("pause");
	// a + F + k - V - m - x + b - S = 2.213 + 3 + 2.213 - 3.312 - 2 - 3.312 - 2.213 - 3
	// a + F + k - V - m - x + b - S = 

	double _q = 1, _w = 7, _e = 2, _r = 7, _t = 2.213, _y = 2.213, _u = 2.213, _i = 2.213, _o = 2.213, _p = 2.213,
		_a = 2.213, _s = 2.213, _d = 2.213, _f = 2.213, _g = 2.213, _h = 2.213, _j = 2.213, _k = 2.213, _l = 2.213,
		_z = 2.213, _x = 2.213, _c = 2.213, _v = 2.213, _b = 3.312, _n = 3.312, _m = 3.312, _Q = 3.312, _W = 3.312,
		_E = 3.312, _R = 3.312, _T = 3.312, _Y = 3.312, _U = 3.312, _I = 3.312, _O = 3.312, _P = 3, _A = 3, _S = 3,
		_D = 3, _F = 3, _G = 3, _H = 3, _J = 3, _K = 3, _L = 3, _Z = 3, _X = 3, _C = 2, _V = 2, _B = 2, _N = 2,
		_M = 2;
	te_variable vars[] = { 
		{"q", &_q}, {"w", &_w}, {"e", &_e}, {"r", &_r}, {"t", &_t}, {"y", &_y}, {"u", &_u},
		{"i", &_i}, {"o", &_o}, {"p", &_p}, {"a", &_a}, {"s", &_s}, {"d", &_d}, {"f", &_f}, 
		{"g", &_g}, {"h", &_h}, {"j", &_j}, {"k", &_k}, {"l", &_l}, {"z", &_z}, {"x", &_x}, 
		{"c", &_c}, {"v", &_v}, {"b", &_b}, {"n", &_n}, {"m", &_m}, {"Q", &_Q}, {"W", &_W}, 
		{"E", &_E}, {"R", &_R}, {"T", &_T}, {"Y", &_Y}, {"U", &_U}, {"I", &_I}, {"O", &_O}, 
		{"P", &_P}, {"A", &_A}, {"S", &_S}, {"D", &_D}, {"F", &_F}, {"G", &_G}, {"H", &_H}, 
		{"J", &_J}, {"K", &_K}, {"L", &_L}, {"Z", &_Z}, {"X", &_X}, {"C", &_C}, {"V", &_V}, 
		{"B", &_B}, {"N", &_N}, {"M", &_M} 
	};
	std::vector<const char*> tinyexpr_exprs;

	std::cout << "\nGenerate random int: " << XE::Generator::GenerateRandomIntNumber(5);
	std::cout << "\nGenerate random int: " << XE::Generator::GenerateRandomIntNumber(5);
	std::cout << "\nGenerate random int: " << XE::Generator::GenerateRandomIntNumber(5);
	std::cout << "\nGenerate random int: " << XE::Generator::GenerateRandomIntNumber(5);
	std::cout << "\nGenerate random int: " << XE::Generator::GenerateRandomIntNumber(5);
	std::cout << "\nGenerate random int: " << XE::Generator::GenerateRandomIntNumber(5)
		<< "\n 1) " << XE::Generator::GenerateExpr(XE::Generator::mass_schemes[0][0])
		<< "\n 2) " << XE::Generator::GenerateExpr(XE::Generator::mass_schemes[1][0])
		<< "\n 3) " << XE::Generator::GenerateExpr(XE::Generator::mass_schemes[2][0])
		<< "\n 4) " << XE::Generator::GenerateExpr(XE::Generator::mass_schemes[3][0])
		<< "\n 5) " << XE::Generator::GenerateExpr(XE::Generator::mass_schemes[4][0])
		<< "\n 6) " << XE::Generator::GenerateExpr(XE::Generator::mass_schemes[5][0])
		<< "\n 7) " << XE::Generator::GenerateExpr(XE::Generator::mass_schemes[6][0])
		<< "\n 8) " << XE::Generator::GenerateExpr(XE::Generator::mass_schemes[7][0])
		<< "\n 9) " << XE::Generator::GenerateExpr(XE::Generator::mass_schemes[8][0])
		<< "\n 10) " << XE::Generator::GenerateExpr(XE::Generator::mass_schemes[9][0])
		<< "\n 11) " << XE::Generator::GenerateExpr(XE::Generator::mass_schemes[10][0])
		<< "\n 12) " << XE::Generator::GenerateExpr(XE::Generator::mass_schemes[11][0])
		<< "\n 13) " << XE::Generator::GenerateExpr(XE::Generator::mass_schemes[12][0])
		<< "\n 14) " << XE::Generator::GenerateExpr(XE::Generator::mass_schemes[13][0])
		<< "\n 15) " << XE::Generator::GenerateExpr(XE::Generator::mass_schemes[14][0])
		<< "\n 16) " << XE::Generator::GenerateExpr(XE::Generator::mass_schemes[15][0])
		<< "\n 17) " << XE::Generator::GenerateExpr(XE::Generator::mass_schemes[16][0])
		<< "\n 18) " << XE::Generator::GenerateExpr(XE::Generator::mass_schemes[17][0])
		<< "\n 19) " << XE::Generator::GenerateExpr(XE::Generator::mass_schemes[18][0])
		<< "\n 20) " << XE::Generator::GenerateExpr(XE::Generator::mass_schemes[19][0])
		<< "\n 21) " << XE::Generator::GenerateExpr(XE::Generator::mass_schemes[20][0])
		<< "\n 22) " << XE::Generator::GenerateExpr(XE::Generator::mass_schemes[21][0])
		<< "\n 23) " << XE::Generator::GenerateExpr(XE::Generator::mass_schemes[22][0])
		<< "\n 24) " << XE::Generator::GenerateExpr(XE::Generator::mass_schemes[23][0])
		<< "\n 25) " << XE::Generator::GenerateExpr(XE::Generator::mass_schemes[24][0])
		<< "\n 26) " << XE::Generator::GenerateExpr(XE::Generator::mass_schemes[25][0]);
	start_time = clock();
	XE::Generator::Generate();
	end_time = clock();
	int generate_time = end_time - start_time;
	std::cout << "\n\n\n";//<< XE::Bench::all_benchs[0][0];

	std::vector<double> pass1;
	std::vector<double> pass2;

	start_time = clock();
	for (auto& elem : XE::Bench::all_benchs) {
		for (auto& expression : elem) {
			if (!expression.empty()) {
				d.calculate(expression);
				pass1.push_back(d.calculate(expression));
				/*if (isnan(d.calculate(expression))) {
					std::cout << "\n\n\nALARM: " << expression << "\n\n\n";
					d.calculate(expression);
				}*/
			}
		}
	}
	end_time = clock();

	int massive = 0;
	for (auto& elem : XE::Bench::all_benchs) {
		for (auto& element : elem) {
			if (!element.empty()) {
				massive++;
				std::string temp = fix_fac_for_tinyexpr(element);
				//const char* str = temp.c_str();
				element = temp;
				tinyexpr_exprs.push_back(element.c_str());
			}
		}
	}
	
	/*int i1 = 0;
	for (auto& elem : XE::Bench::all_benchs) {
		for (auto& expression : elem) {
			if (!expression.empty()) {
				std::cout << "\nMy lib solve: " << d.calculate(expression) << " | " << i1++ << "/" << massive;
			}
		}
	}*/

	int start_time2 = clock();
	for (auto& element : tinyexpr_exprs) {
		//te_interp(element, 0);
		te_expr* n = te_compile(element, vars, 52, 0);
		te_eval(n);
		pass2.push_back(te_eval(n));
	}
	int end_time2 = clock();
	//int i1 = 0;
	//for (auto& element : tinyexpr_exprs) {
	//	std::cout << "\nExpr: " << element;
	//	te_expr* n = te_compile(element, vars, 52, 0);
	//	std::cout << "\nTinyexpr solve: " << te_eval(n) << " | " << i1++ << "/" << massive;
	//	//std::cout << "\nTinyexpr solve: " << te_interp(element, 0) << " | " << i1++ << "/" << massive;
	//}

	double answer;
	te_expr* n = te_compile("cos(7) + tan(6) + log(2) + 5 - log(2) + 4 - log(7) + 7 - sin(8)", vars, 52, 0);
	answer = te_eval(n);

	std::cout << "\nMass count: " << massive << " \nGenerate time: " << generate_time << "ms";
	std::cout << "\nSolve my lib time: " << end_time - start_time << "ms";
	std::cout << "\nSolve tiny expr time: " << end_time2 - start_time2 << "ms\n" << answer << "\n";
	//((abs(4) - sinh(5)) + (tan(1) + sin(6)) - tan(1))
	system("pause");
	int sz1 = pass1.size();
	int sz2 = pass2.size();
	std::cout << "\nEqual sizes: " << (sz1 == sz2 ? "[CORRECT]" : "[NO]");
	for (int i = 0; i < sz1; i++) {
		std::cout << color(white) << "\nMy lib: " << pass1[i] << " | " << "Tiny expr: " << pass2[i] << " | eq? ";
		if ((round(pass1[i] * 10000) / 10000) == (round(pass2[i] * 10000) / 10000)) {
			std::cout << color(green) << "[CORRECT]";
		}
		else if ((pass1[i] < (pass2[i] + 1)) && (pass1[i] > (pass2[i] - 1))) {
			std::cout << color(yellow) << "[NORMAL]";
		}
		else {
			std::cout << color(red) << "[BAD]" << " | formula: " << tinyexpr_exprs[i];
		}
		std::cout << color(white) << " | (" << i << " / " << sz1 << ")";

		//std::cout << "\nMy lib: " << pass1[i] << " | " << "Tiny expr: " << pass2[i] << " | eq? " << (pass1[i] == pass2[i] ? color(green), "[CORRECT]" : (pass1[i] < (pass2[i] + 1)) && (pass1[i] > (pass2[i] - 1)) ? color(yellow), "[NORMAL]" : (color(red), "[NO]")) << " | (" << i << " / " << sz1 << ")";
	}


	return 0;
}
