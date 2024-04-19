#include <string>
#include <map>
#include <stack>
#include <iostream>

using namespace std;

#define atividade "05"
#define nome "Marcos Vitor Souza Freire"
#define matricula "552355"


// Atividade 5

// Usando a pilha do STL do C++ implemente um avaliador de expressões numéricas cujas expressões, dadas como 
// strings de entrada, devem ter as seguintes características:

// - Ser formada for letras, operadores, números e parênteses.

// - As letras formam nomes de variáveis e as constantes podem ser números reais ou inteiros. Exemplo,
// "x+beta-1.0" => possui as variáveis x e beta, os operadores + e - e a constante numérica 1.0

// - Os operadores computáveis são em ordem de precedêcia: "(+-*/^" onde "^" é o operador de potência.

// - Espaços em branco devem ser ignoráveis e outros caracteres diferentes dos apresentados devem ser 
// considerados erros. Por exemplo, "alpha+gama0+2!"  => são erros "gama0" pois é uma variável contendo 
// um caractere não letra,  Em "2!" o caractere é inválido.

// - O valor das variáveis é uma entrada representada pela estrutura de dados map da STL do C++. 
// Veja exemplo de uso do map a seguir:

/*
    int main() {
        map<string, float> m;
        m["x"] = 21.5; // carrega 'x'
        m["beta"] = 14.72; // carrega 'beta'
    }
*/


bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool isVariableOrConstant(char c) {
    return isalpha(c) || isdigit(c) || c == '.';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

float applyOperation(float a, float b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^':
            float result = 1;
            for (int i = 0; i < static_cast<int>(b); ++i) {
                result *= a;
            }
            return result;
        
    }
}

float xEval(string expression, map<string, float>& variables) {
    stack<float> values;
    stack<char> ops;

    for (size_t i = 0; i < expression.length(); ++i) {
        if (isspace(expression[i])) continue;

        if (isalpha(expression[i])) {
            string varName;
            while (i < expression.length() && isalpha(expression[i])) {
                varName += expression[i++];
            }
            --i;

            if (variables.find(varName) == variables.end()) {
                cerr << "Erro: Variável " << varName << " não definida." << endl;
                return 0;
            }

            values.push(variables.at(varName));
        } else if (isdigit(expression[i]) || expression[i] == '.') {
            string numStr;
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                numStr += expression[i++];
            }
            --i;

            float num = stof(numStr);
            values.push(num);
        } else if (expression[i] == '(') {
            ops.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                float b = values.top(); values.pop();
                float a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperation(a, b, op));
            }
            if (!ops.empty()) ops.pop();
        } else if (isOperator(expression[i])) {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i])) {
                float b = values.top(); values.pop();
                float a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperation(a, b, op));
            }
            ops.push(expression[i]);
        } else {
            cerr << "Erro: Caractere inválido na expressão." << endl;
            return 0;
        }
    }

    while (!ops.empty()) {
        float b = values.top(); values.pop();
        float a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOperation(a, b, op));
    }

    return values.top();
}
