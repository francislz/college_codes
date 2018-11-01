from JavaLexer import JavaLexer
import antlr4

lexer = JavaLexer(input="Teste.java")

tokens = antlr4.CommonTokenStream(lexer)
tokens.fill()
print([token.text for token in tokens.tokens][:-1])
