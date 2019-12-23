#pragma once
#include "stack_on_array.h"
#include <iostream>
#include <string> 
class Calc {
private:
	static bool is_digit(const char ch) {
		if (ch < '0' || ch > '9') return false;
		else return true;
	}

	static bool SkipSpaces(const std::string& str, int& i) {
		while (str[i] && str[i] == ' ') {
			++i;
		}
		return str[i];
	}

	static std::string GetNumberFrom(const std::string& str, int& i) {
		std::string tmp;
		do {
			tmp += str[i];
			++i;
		} while (is_digit(str[i]));
		return tmp;
	}

	static void PushProperOperationsToOut(Stack<char>& operations, Stack<std::string>& out) {
		char tmp;
		while (!operations.empty() && operations.top() != '(') {
			operations >> tmp;
			out << std::string{ tmp };
		}
	}

	static void PushOneOperationToOut(Stack<char>& operations, Stack<std::string>& out) {
		char top_oper;
		operations >> top_oper;
		out << std::string{ top_oper };
	}

public:
	static std::string ConvertPolishStackIntoString(const Stack<std::string>& st) {
		std::string out = "";
		for (int i = 0; i < st.size(); i++) {
			out += st[i] + " ";
		}
		return out;
	}

	static int Prior(const char ch) {
		switch (ch) {
		case '*':case '/':
			return 2;

		case '+': case '-':
			return 1;

		default:
			return 0;
		}
	}

	static Stack<std::string> ConvertingStringToPolishStack(const std::string& str) {
		Stack<char> operations;
		Stack<std::string> out;
		bool prev_was_a_numb = false;				
		bool is_neg_numb = false;
		bool prev_was_bracket = true;				// to check for negative numbers
		for (int i = 0; SkipSpaces(str, i) && i < str.length();) {
			if (is_digit(str[i])) {					// read the number and push it into the queue
				prev_was_bracket = false;
				if (prev_was_a_numb) {
					throw std::exception("incorrect expression");
				}
				else {
					if (is_neg_numb) {
						out << "-" + GetNumberFrom(str, i);
						prev_was_a_numb = true;
						is_neg_numb = false;
						continue;
					}
					else {
						out << GetNumberFrom(str, i);
						prev_was_a_numb = true;
						continue;
					}
				}
			}
			else {
				prev_was_a_numb = false;

				switch (str[i]) {
				case '(':
					operations << str[i];
					prev_was_bracket = true;
					break;

				case '*': case '/': case '+':
					if (str[i] == '-' && prev_was_bracket) {
						is_neg_numb = true;
						break;
					}
					else {
						if (operations.empty() || Prior(operations.top()) < Prior(str[i])) {
							operations << str[i];
						}
						else {
							if (Prior(operations.top()) == Prior(str[i])) {
								PushOneOperationToOut(operations, out);
								operations << str[i];
							}
							else {
								PushProperOperationsToOut(operations, out);
								operations << str[i];
							}
						}
						break;
					}

				case '-':
					if (prev_was_bracket) {
						is_neg_numb = true;
						break;
					}
					else {
						if (operations.empty() || Prior(operations.top()) < Prior(str[i])) {
							operations << str[i];
						}
						else {
							if (Prior(operations.top()) == Prior(str[i])) {
								PushOneOperationToOut(operations, out);
								operations << str[i];
							}
							else {
								PushProperOperationsToOut(operations, out);
								operations << str[i];
							}
						}
						break;
					}

				case ')':
					PushProperOperationsToOut(operations, out);
					if (operations.empty() || operations.top() != '(') {
						throw std::exception("incorrect expression");
					}
					char tmp;
					operations >> tmp;
					break;

				default:
					char throwing_str[17] = "unnamed symbol ";
					throwing_str[15] = str[i];
					throw std::exception(throwing_str);
				}
				++i;
				if (prev_was_bracket) continue;
				if (is_neg_numb) continue;
				is_neg_numb = false;
				prev_was_bracket = false;
			}
		}
		PushProperOperationsToOut(operations, out);
		if (!operations.empty()) {
			throw std::exception("incorrect expression");
		}
		return out;
	}

	static double GetResult(Stack<std::string>& out) {
		Stack <double> ans;
		int i = 0;
		while (i < out.size()) {
				if (out[i] == "+") {
					if (ans.size() < 2) {
						throw std::exception("incorrect expression");
					}
					double top_elem;
					ans >> top_elem;
					ans.top() += top_elem;
				}
				else {
					if (out[i] == "-") {
						if (ans.size() < 2) {
							throw std::exception("incorrect expression");
						}
						double top_elem;
						ans >> top_elem;
						ans.top() -= top_elem;
					}
					else {
						if (out[i] == "*") {
							if (ans.size() < 2) {
								throw std::exception("incorrect expression");
							}
							double top_elem;
							ans >> top_elem;
							ans.top() *= top_elem;
						}
						else {
							if (out[i] == "/") {
								if (ans.size() < 2) {
									throw std::exception("incorrect expression");
								}
								double top_elem;
								ans >> top_elem;
								ans.top() /= top_elem;
							}
							else {
								ans << std::stoi(out[i]);
							}
						}
					}
				}
			++i;
		}
		if (ans.size() != 1) {
			throw std::exception("incorrect expression");
		}
		return ans.top();
	}
};