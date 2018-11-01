# Generated from /home/franciscone/IdeaProjects/Lexical/src/JavaLexer.g4 by ANTLR 4.7
# encoding: utf-8
from __future__ import print_function
from antlr4 import *
from io import StringIO
import sys


def serializedATN():
    with StringIO() as buf:
        buf.write(u"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2")
        buf.write(u"\66\u020f\b\1\4\2\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6")
        buf.write(u"\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t\13\4\f\t\f\4")
        buf.write(u"\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t")
        buf.write(u"\22\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27")
        buf.write(u"\4\30\t\30\4\31\t\31\4\32\t\32\4\33\t\33\4\34\t\34\4")
        buf.write(u"\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!\t!\4\"\t\"\4#\t")
        buf.write(u"#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t+\4")
        buf.write(u",\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\4\62\t\62")
        buf.write(u"\4\63\t\63\4\64\t\64\4\65\t\65\4\66\t\66\4\67\t\67\3")
        buf.write(u"\2\3\2\3\3\3\3\3\4\6\4u\n\4\r\4\16\4v\3\4\3\4\3\5\3\5")
        buf.write(u"\3\5\3\5\7\5\177\n\5\f\5\16\5\u0082\13\5\3\5\3\5\3\6")
        buf.write(u"\3\6\7\6\u0088\n\6\f\6\16\6\u008b\13\6\3\7\3\7\3\7\3")
        buf.write(u"\7\3\7\3\7\3\b\3\b\3\b\3\b\3\b\3\t\3\t\3\t\3\t\3\n\3")
        buf.write(u"\n\3\n\3\n\3\n\3\13\3\13\3\13\3\13\3\13\3\f\3\f\3\f\3")
        buf.write(u"\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\5\f\u00b1\n\f\3\r\3\r")
        buf.write(u"\3\r\3\r\3\r\3\r\3\r\3\r\3\16\3\16\3\16\3\16\3\17\3\17")
        buf.write(u"\3\17\3\17\3\17\3\17\3\17\3\17\3\20\3\20\3\20\3\20\3")
        buf.write(u"\20\3\20\3\20\3\21\3\21\3\21\3\21\3\21\3\21\3\22\3\22")
        buf.write(u"\3\22\3\22\3\22\3\22\3\22\3\22\3\22\3\22\3\22\3\23\3")
        buf.write(u"\23\3\23\3\23\3\23\3\24\3\24\3\24\3\24\3\24\3\24\3\25")
        buf.write(u"\3\25\3\25\3\25\3\25\3\25\3\25\3\25\3\25\3\26\3\26\3")
        buf.write(u"\26\3\26\3\26\3\26\3\27\3\27\3\27\3\27\3\27\3\27\3\27")
        buf.write(u"\3\30\3\30\3\30\3\30\3\30\3\30\3\30\3\30\3\31\3\31\3")
        buf.write(u"\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\32\3\32\3\32")
        buf.write(u"\3\32\3\32\3\32\3\32\3\32\3\33\3\33\3\33\3\33\3\33\3")
        buf.write(u"\33\3\33\3\33\3\33\3\33\3\33\3\34\3\34\3\34\3\34\3\34")
        buf.write(u"\3\34\3\34\3\35\3\35\3\35\3\35\3\35\3\36\3\36\3\36\3")
        buf.write(u"\36\3\36\3\36\3\37\3\37\3\37\3\37\3\37\3\37\3\37\3\37")
        buf.write(u"\3\37\3\37\3 \3 \3 \3 \3 \3 \3 \3 \3 \3!\3!\3!\3!\3!")
        buf.write(u"\3!\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3#\3#\3#\3#\3#\3$\3$")
        buf.write(u"\3$\3$\3$\3$\3$\3$\3$\3$\3$\3$\3$\3%\3%\3%\3%\3%\3%\3")
        buf.write(u"%\3&\3&\3&\3&\3&\3&\3&\3&\3&\3&\3\'\3\'\3\'\3\'\3\'\3")
        buf.write(u"\'\3\'\3\'\3\'\3\'\3\'\3\'\3\'\3\'\3\'\3\'\3\'\3\'\3")
        buf.write(u"\'\3\'\3\'\3\'\3\'\3\'\3\'\3\'\3\'\5\'\u0195\n\'\3(\3")
        buf.write(u"(\3)\3)\3)\3)\3)\3)\3)\3)\3)\3)\3)\5)\u01a4\n)\3*\3*")
        buf.write(u"\3*\3*\5*\u01aa\n*\3+\3+\3,\3,\3-\3-\3.\3.\3/\3/\3\60")
        buf.write(u"\3\60\3\61\3\61\3\62\3\62\3\63\3\63\3\63\3\63\3\63\3")
        buf.write(u"\63\3\63\3\63\3\63\3\63\3\63\3\63\3\63\3\63\3\63\3\63")
        buf.write(u"\3\63\3\63\3\63\3\63\3\63\3\63\3\63\5\63\u01d3\n\63\3")
        buf.write(u"\64\3\64\3\64\3\64\3\64\3\64\3\64\3\64\3\64\3\64\5\64")
        buf.write(u"\u01df\n\64\3\65\3\65\3\65\3\65\3\65\3\65\3\65\3\65\3")
        buf.write(u"\65\3\65\3\65\3\65\3\65\3\65\3\65\3\65\3\65\3\65\3\65")
        buf.write(u"\5\65\u01f4\n\65\3\66\3\66\3\66\3\66\3\66\3\66\3\66\3")
        buf.write(u"\66\3\66\3\66\3\66\3\66\3\66\3\66\3\66\5\66\u0205\n\66")
        buf.write(u"\3\67\3\67\3\67\3\67\7\67\u020b\n\67\f\67\16\67\u020e")
        buf.write(u"\13\67\2\28\3\2\5\2\7\3\t\4\13\5\r\6\17\7\21\b\23\t\25")
        buf.write(u"\n\27\13\31\f\33\r\35\16\37\17!\20#\21%\22\'\23)\24+")
        buf.write(u"\25-\26/\27\61\30\63\31\65\32\67\339\34;\35=\36?\37A")
        buf.write(u" C!E\"G#I$K%M&O\'Q(S)U*W+Y,[-]._/a\60c\61e\62g\63i\64")
        buf.write(u"k\65m\66\3\2\b\4\2C\\c|\5\2\13\f\16\17\"\"\4\2\f\f\17")
        buf.write(u"\17\5\2,-//\61\61\4\2((``\6\2##\60\60<<AA\2\u022e\2\7")
        buf.write(u"\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3")
        buf.write(u"\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3")
        buf.write(u"\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3")
        buf.write(u"\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2")
        buf.write(u")\3\2\2\2\2+\3\2\2\2\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2")
        buf.write(u"\2\2\63\3\2\2\2\2\65\3\2\2\2\2\67\3\2\2\2\29\3\2\2\2")
        buf.write(u"\2;\3\2\2\2\2=\3\2\2\2\2?\3\2\2\2\2A\3\2\2\2\2C\3\2\2")
        buf.write(u"\2\2E\3\2\2\2\2G\3\2\2\2\2I\3\2\2\2\2K\3\2\2\2\2M\3\2")
        buf.write(u"\2\2\2O\3\2\2\2\2Q\3\2\2\2\2S\3\2\2\2\2U\3\2\2\2\2W\3")
        buf.write(u"\2\2\2\2Y\3\2\2\2\2[\3\2\2\2\2]\3\2\2\2\2_\3\2\2\2\2")
        buf.write(u"a\3\2\2\2\2c\3\2\2\2\2e\3\2\2\2\2g\3\2\2\2\2i\3\2\2\2")
        buf.write(u"\2k\3\2\2\2\2m\3\2\2\2\3o\3\2\2\2\5q\3\2\2\2\7t\3\2\2")
        buf.write(u"\2\tz\3\2\2\2\13\u0085\3\2\2\2\r\u008c\3\2\2\2\17\u0092")
        buf.write(u"\3\2\2\2\21\u0097\3\2\2\2\23\u009b\3\2\2\2\25\u00a0\3")
        buf.write(u"\2\2\2\27\u00b0\3\2\2\2\31\u00b2\3\2\2\2\33\u00ba\3\2")
        buf.write(u"\2\2\35\u00be\3\2\2\2\37\u00c6\3\2\2\2!\u00cd\3\2\2\2")
        buf.write(u"#\u00d3\3\2\2\2%\u00de\3\2\2\2\'\u00e3\3\2\2\2)\u00e9")
        buf.write(u"\3\2\2\2+\u00f2\3\2\2\2-\u00f8\3\2\2\2/\u00ff\3\2\2\2")
        buf.write(u"\61\u0107\3\2\2\2\63\u0111\3\2\2\2\65\u0119\3\2\2\2\67")
        buf.write(u"\u0124\3\2\2\29\u012b\3\2\2\2;\u0130\3\2\2\2=\u0136\3")
        buf.write(u"\2\2\2?\u0140\3\2\2\2A\u0149\3\2\2\2C\u014f\3\2\2\2E")
        buf.write(u"\u0156\3\2\2\2G\u015b\3\2\2\2I\u0168\3\2\2\2K\u016f\3")
        buf.write(u"\2\2\2M\u0194\3\2\2\2O\u0196\3\2\2\2Q\u01a3\3\2\2\2S")
        buf.write(u"\u01a9\3\2\2\2U\u01ab\3\2\2\2W\u01ad\3\2\2\2Y\u01af\3")
        buf.write(u"\2\2\2[\u01b1\3\2\2\2]\u01b3\3\2\2\2_\u01b5\3\2\2\2a")
        buf.write(u"\u01b7\3\2\2\2c\u01b9\3\2\2\2e\u01d2\3\2\2\2g\u01de\3")
        buf.write(u"\2\2\2i\u01f3\3\2\2\2k\u0204\3\2\2\2m\u0206\3\2\2\2o")
        buf.write(u"p\t\2\2\2p\4\3\2\2\2qr\4\62;\2r\6\3\2\2\2su\t\3\2\2t")
        buf.write(u"s\3\2\2\2uv\3\2\2\2vt\3\2\2\2vw\3\2\2\2wx\3\2\2\2xy\b")
        buf.write(u"\4\2\2y\b\3\2\2\2z{\7\61\2\2{|\7\61\2\2|\u0080\3\2\2")
        buf.write(u"\2}\177\n\4\2\2~}\3\2\2\2\177\u0082\3\2\2\2\u0080~\3")
        buf.write(u"\2\2\2\u0080\u0081\3\2\2\2\u0081\u0083\3\2\2\2\u0082")
        buf.write(u"\u0080\3\2\2\2\u0083\u0084\b\5\2\2\u0084\n\3\2\2\2\u0085")
        buf.write(u"\u0089\4\63;\2\u0086\u0088\5\5\3\2\u0087\u0086\3\2\2")
        buf.write(u"\2\u0088\u008b\3\2\2\2\u0089\u0087\3\2\2\2\u0089\u008a")
        buf.write(u"\3\2\2\2\u008a\f\3\2\2\2\u008b\u0089\3\2\2\2\u008c\u008d")
        buf.write(u"\7u\2\2\u008d\u008e\7j\2\2\u008e\u008f\7q\2\2\u008f\u0090")
        buf.write(u"\7t\2\2\u0090\u0091\7v\2\2\u0091\16\3\2\2\2\u0092\u0093")
        buf.write(u"\7d\2\2\u0093\u0094\7{\2\2\u0094\u0095\7v\2\2\u0095\u0096")
        buf.write(u"\7g\2\2\u0096\20\3\2\2\2\u0097\u0098\7k\2\2\u0098\u0099")
        buf.write(u"\7p\2\2\u0099\u009a\7v\2\2\u009a\22\3\2\2\2\u009b\u009c")
        buf.write(u"\7n\2\2\u009c\u009d\7q\2\2\u009d\u009e\7p\2\2\u009e\u009f")
        buf.write(u"\7i\2\2\u009f\24\3\2\2\2\u00a0\u00a1\7e\2\2\u00a1\u00a2")
        buf.write(u"\7j\2\2\u00a2\u00a3\7c\2\2\u00a3\u00a4\7t\2\2\u00a4\26")
        buf.write(u"\3\2\2\2\u00a5\u00a6\7h\2\2\u00a6\u00a7\7n\2\2\u00a7")
        buf.write(u"\u00a8\7q\2\2\u00a8\u00a9\7c\2\2\u00a9\u00b1\7v\2\2\u00aa")
        buf.write(u"\u00ab\7f\2\2\u00ab\u00ac\7q\2\2\u00ac\u00ad\7w\2\2\u00ad")
        buf.write(u"\u00ae\7d\2\2\u00ae\u00af\7n\2\2\u00af\u00b1\7g\2\2\u00b0")
        buf.write(u"\u00a5\3\2\2\2\u00b0\u00aa\3\2\2\2\u00b1\30\3\2\2\2\u00b2")
        buf.write(u"\u00b3\7d\2\2\u00b3\u00b4\7q\2\2\u00b4\u00b5\7q\2\2\u00b5")
        buf.write(u"\u00b6\7n\2\2\u00b6\u00b7\7g\2\2\u00b7\u00b8\7c\2\2\u00b8")
        buf.write(u"\u00b9\7p\2\2\u00b9\32\3\2\2\2\u00ba\u00bb\7p\2\2\u00bb")
        buf.write(u"\u00bc\7g\2\2\u00bc\u00bd\7y\2\2\u00bd\34\3\2\2\2\u00be")
        buf.write(u"\u00bf\7r\2\2\u00bf\u00c0\7c\2\2\u00c0\u00c1\7e\2\2\u00c1")
        buf.write(u"\u00c2\7m\2\2\u00c2\u00c3\7c\2\2\u00c3\u00c4\7i\2\2\u00c4")
        buf.write(u"\u00c5\7g\2\2\u00c5\36\3\2\2\2\u00c6\u00c7\7k\2\2\u00c7")
        buf.write(u"\u00c8\7o\2\2\u00c8\u00c9\7r\2\2\u00c9\u00ca\7q\2\2\u00ca")
        buf.write(u"\u00cb\7t\2\2\u00cb\u00cc\7v\2\2\u00cc \3\2\2\2\u00cd")
        buf.write(u"\u00ce\7e\2\2\u00ce\u00cf\7q\2\2\u00cf\u00d0\7p\2\2\u00d0")
        buf.write(u"\u00d1\7u\2\2\u00d1\u00d2\7v\2\2\u00d2\"\3\2\2\2\u00d3")
        buf.write(u"\u00d4\7k\2\2\u00d4\u00d5\7p\2\2\u00d5\u00d6\7u\2\2\u00d6")
        buf.write(u"\u00d7\7v\2\2\u00d7\u00d8\7c\2\2\u00d8\u00d9\7p\2\2\u00d9")
        buf.write(u"\u00da\7e\2\2\u00da\u00db\7g\2\2\u00db\u00dc\7q\2\2\u00dc")
        buf.write(u"\u00dd\7h\2\2\u00dd$\3\2\2\2\u00de\u00df\7i\2\2\u00df")
        buf.write(u"\u00e0\7q\2\2\u00e0\u00e1\7v\2\2\u00e1\u00e2\7q\2\2\u00e2")
        buf.write(u"&\3\2\2\2\u00e3\u00e4\7e\2\2\u00e4\u00e5\7n\2\2\u00e5")
        buf.write(u"\u00e6\7c\2\2\u00e6\u00e7\7u\2\2\u00e7\u00e8\7u\2\2\u00e8")
        buf.write(u"(\3\2\2\2\u00e9\u00ea\7c\2\2\u00ea\u00eb\7d\2\2\u00eb")
        buf.write(u"\u00ec\7u\2\2\u00ec\u00ed\7v\2\2\u00ed\u00ee\7t\2\2\u00ee")
        buf.write(u"\u00ef\7c\2\2\u00ef\u00f0\7e\2\2\u00f0\u00f1\7v\2\2\u00f1")
        buf.write(u"*\3\2\2\2\u00f2\u00f3\7h\2\2\u00f3\u00f4\7k\2\2\u00f4")
        buf.write(u"\u00f5\7p\2\2\u00f5\u00f6\7c\2\2\u00f6\u00f7\7n\2\2\u00f7")
        buf.write(u",\3\2\2\2\u00f8\u00f9\7r\2\2\u00f9\u00fa\7w\2\2\u00fa")
        buf.write(u"\u00fb\7d\2\2\u00fb\u00fc\7n\2\2\u00fc\u00fd\7k\2\2\u00fd")
        buf.write(u"\u00fe\7e\2\2\u00fe.\3\2\2\2\u00ff\u0100\7r\2\2\u0100")
        buf.write(u"\u0101\7t\2\2\u0101\u0102\7k\2\2\u0102\u0103\7x\2\2\u0103")
        buf.write(u"\u0104\7c\2\2\u0104\u0105\7v\2\2\u0105\u0106\7g\2\2\u0106")
        buf.write(u"\60\3\2\2\2\u0107\u0108\7r\2\2\u0108\u0109\7t\2\2\u0109")
        buf.write(u"\u010a\7q\2\2\u010a\u010b\7v\2\2\u010b\u010c\7g\2\2\u010c")
        buf.write(u"\u010d\7e\2\2\u010d\u010e\7v\2\2\u010e\u010f\7g\2\2\u010f")
        buf.write(u"\u0110\7f\2\2\u0110\62\3\2\2\2\u0111\u0112\7g\2\2\u0112")
        buf.write(u"\u0113\7z\2\2\u0113\u0114\7v\2\2\u0114\u0115\7g\2\2\u0115")
        buf.write(u"\u0116\7p\2\2\u0116\u0117\7f\2\2\u0117\u0118\7u\2\2\u0118")
        buf.write(u"\64\3\2\2\2\u0119\u011a\7k\2\2\u011a\u011b\7o\2\2\u011b")
        buf.write(u"\u011c\7r\2\2\u011c\u011d\7n\2\2\u011d\u011e\7g\2\2\u011e")
        buf.write(u"\u011f\7o\2\2\u011f\u0120\7g\2\2\u0120\u0121\7p\2\2\u0121")
        buf.write(u"\u0122\7v\2\2\u0122\u0123\7u\2\2\u0123\66\3\2\2\2\u0124")
        buf.write(u"\u0125\7u\2\2\u0125\u0126\7v\2\2\u0126\u0127\7c\2\2\u0127")
        buf.write(u"\u0128\7v\2\2\u0128\u0129\7k\2\2\u0129\u012a\7e\2\2\u012a")
        buf.write(u"8\3\2\2\2\u012b\u012c\7v\2\2\u012c\u012d\7j\2\2\u012d")
        buf.write(u"\u012e\7k\2\2\u012e\u012f\7u\2\2\u012f:\3\2\2\2\u0130")
        buf.write(u"\u0131\7u\2\2\u0131\u0132\7w\2\2\u0132\u0133\7r\2\2\u0133")
        buf.write(u"\u0134\7g\2\2\u0134\u0135\7t\2\2\u0135<\3\2\2\2\u0136")
        buf.write(u"\u0137\7v\2\2\u0137\u0138\7t\2\2\u0138\u0139\7c\2\2\u0139")
        buf.write(u"\u013a\7p\2\2\u013a\u013b\7u\2\2\u013b\u013c\7k\2\2\u013c")
        buf.write(u"\u013d\7g\2\2\u013d\u013e\7p\2\2\u013e\u013f\7v\2\2\u013f")
        buf.write(u">\3\2\2\2\u0140\u0141\7x\2\2\u0141\u0142\7q\2\2\u0142")
        buf.write(u"\u0143\7n\2\2\u0143\u0144\7c\2\2\u0144\u0145\7v\2\2\u0145")
        buf.write(u"\u0146\7k\2\2\u0146\u0147\7n\2\2\u0147\u0148\7g\2\2\u0148")
        buf.write(u"@\3\2\2\2\u0149\u014a\7v\2\2\u014a\u014b\7j\2\2\u014b")
        buf.write(u"\u014c\7t\2\2\u014c\u014d\7q\2\2\u014d\u014e\7y\2\2\u014e")
        buf.write(u"B\3\2\2\2\u014f\u0150\7v\2\2\u0150\u0151\7j\2\2\u0151")
        buf.write(u"\u0152\7t\2\2\u0152\u0153\7q\2\2\u0153\u0154\7y\2\2\u0154")
        buf.write(u"\u0155\7u\2\2\u0155D\3\2\2\2\u0156\u0157\7x\2\2\u0157")
        buf.write(u"\u0158\7q\2\2\u0158\u0159\7k\2\2\u0159\u015a\7f\2\2\u015a")
        buf.write(u"F\3\2\2\2\u015b\u015c\7u\2\2\u015c\u015d\7{\2\2\u015d")
        buf.write(u"\u015e\7p\2\2\u015e\u015f\7e\2\2\u015f\u0160\7j\2\2\u0160")
        buf.write(u"\u0161\7t\2\2\u0161\u0162\7q\2\2\u0162\u0163\7p\2\2\u0163")
        buf.write(u"\u0164\7k\2\2\u0164\u0165\7|\2\2\u0165\u0166\7g\2\2\u0166")
        buf.write(u"\u0167\7f\2\2\u0167H\3\2\2\2\u0168\u0169\7p\2\2\u0169")
        buf.write(u"\u016a\7c\2\2\u016a\u016b\7v\2\2\u016b\u016c\7k\2\2\u016c")
        buf.write(u"\u016d\7x\2\2\u016d\u016e\7g\2\2\u016eJ\3\2\2\2\u016f")
        buf.write(u"\u0170\7k\2\2\u0170\u0171\7p\2\2\u0171\u0172\7v\2\2\u0172")
        buf.write(u"\u0173\7g\2\2\u0173\u0174\7t\2\2\u0174\u0175\7h\2\2\u0175")
        buf.write(u"\u0176\7c\2\2\u0176\u0177\7e\2\2\u0177\u0178\7g\2\2\u0178")
        buf.write(u"L\3\2\2\2\u0179\u0195\7?\2\2\u017a\u017b\7,\2\2\u017b")
        buf.write(u"\u0195\7?\2\2\u017c\u017d\7\61\2\2\u017d\u0195\7?\2\2")
        buf.write(u"\u017e\u017f\7\'\2\2\u017f\u0195\7?\2\2\u0180\u0181\7")
        buf.write(u"-\2\2\u0181\u0195\7?\2\2\u0182\u0183\7-\2\2\u0183\u0195")
        buf.write(u"\7?\2\2\u0184\u0185\7>\2\2\u0185\u0186\7>\2\2\u0186\u0195")
        buf.write(u"\7?\2\2\u0187\u0188\7@\2\2\u0188\u0189\7@\2\2\u0189\u0195")
        buf.write(u"\7?\2\2\u018a\u018b\7@\2\2\u018b\u018c\7@\2\2\u018c\u018d")
        buf.write(u"\7@\2\2\u018d\u0195\7?\2\2\u018e\u018f\7(\2\2\u018f\u0195")
        buf.write(u"\7?\2\2\u0190\u0191\7`\2\2\u0191\u0195\7?\2\2\u0192\u0193")
        buf.write(u"\7~\2\2\u0193\u0195\7?\2\2\u0194\u0179\3\2\2\2\u0194")
        buf.write(u"\u017a\3\2\2\2\u0194\u017c\3\2\2\2\u0194\u017e\3\2\2")
        buf.write(u"\2\u0194\u0180\3\2\2\2\u0194\u0182\3\2\2\2\u0194\u0184")
        buf.write(u"\3\2\2\2\u0194\u0187\3\2\2\2\u0194\u018a\3\2\2\2\u0194")
        buf.write(u"\u018e\3\2\2\2\u0194\u0190\3\2\2\2\u0194\u0192\3\2\2")
        buf.write(u"\2\u0195N\3\2\2\2\u0196\u0197\t\5\2\2\u0197P\3\2\2\2")
        buf.write(u"\u0198\u0199\7~\2\2\u0199\u01a4\7~\2\2\u019a\u019b\7")
        buf.write(u"(\2\2\u019b\u01a4\7(\2\2\u019c\u019d\7?\2\2\u019d\u01a4")
        buf.write(u"\7?\2\2\u019e\u019f\7@\2\2\u019f\u01a4\7?\2\2\u01a0\u01a1")
        buf.write(u"\7>\2\2\u01a1\u01a4\7?\2\2\u01a2\u01a4\t\6\2\2\u01a3")
        buf.write(u"\u0198\3\2\2\2\u01a3\u019a\3\2\2\2\u01a3\u019c\3\2\2")
        buf.write(u"\2\u01a3\u019e\3\2\2\2\u01a3\u01a0\3\2\2\2\u01a3\u01a2")
        buf.write(u"\3\2\2\2\u01a4R\3\2\2\2\u01a5\u01a6\7@\2\2\u01a6\u01aa")
        buf.write(u"\7@\2\2\u01a7\u01a8\7>\2\2\u01a8\u01aa\7>\2\2\u01a9\u01a5")
        buf.write(u"\3\2\2\2\u01a9\u01a7\3\2\2\2\u01aaT\3\2\2\2\u01ab\u01ac")
        buf.write(u"\7]\2\2\u01acV\3\2\2\2\u01ad\u01ae\7_\2\2\u01aeX\3\2")
        buf.write(u"\2\2\u01af\u01b0\7}\2\2\u01b0Z\3\2\2\2\u01b1\u01b2\7")
        buf.write(u"\177\2\2\u01b2\\\3\2\2\2\u01b3\u01b4\7*\2\2\u01b4^\3")
        buf.write(u"\2\2\2\u01b5\u01b6\7+\2\2\u01b6`\3\2\2\2\u01b7\u01b8")
        buf.write(u"\t\7\2\2\u01b8b\3\2\2\2\u01b9\u01ba\7=\2\2\u01bad\3\2")
        buf.write(u"\2\2\u01bb\u01bc\7k\2\2\u01bc\u01d3\7h\2\2\u01bd\u01be")
        buf.write(u"\7g\2\2\u01be\u01bf\7n\2\2\u01bf\u01c0\7u\2\2\u01c0\u01d3")
        buf.write(u"\7g\2\2\u01c1\u01c2\7e\2\2\u01c2\u01c3\7c\2\2\u01c3\u01c4")
        buf.write(u"\7u\2\2\u01c4\u01d3\7g\2\2\u01c5\u01c6\7f\2\2\u01c6\u01c7")
        buf.write(u"\7g\2\2\u01c7\u01c8\7h\2\2\u01c8\u01c9\7c\2\2\u01c9\u01ca")
        buf.write(u"\7w\2\2\u01ca\u01cb\7n\2\2\u01cb\u01d3\7v\2\2\u01cc\u01cd")
        buf.write(u"\7u\2\2\u01cd\u01ce\7y\2\2\u01ce\u01cf\7k\2\2\u01cf\u01d0")
        buf.write(u"\7v\2\2\u01d0\u01d1\7e\2\2\u01d1\u01d3\7j\2\2\u01d2\u01bb")
        buf.write(u"\3\2\2\2\u01d2\u01bd\3\2\2\2\u01d2\u01c1\3\2\2\2\u01d2")
        buf.write(u"\u01c5\3\2\2\2\u01d2\u01cc\3\2\2\2\u01d3f\3\2\2\2\u01d4")
        buf.write(u"\u01d5\7f\2\2\u01d5\u01df\7q\2\2\u01d6\u01d7\7y\2\2\u01d7")
        buf.write(u"\u01d8\7j\2\2\u01d8\u01d9\7k\2\2\u01d9\u01da\7n\2\2\u01da")
        buf.write(u"\u01df\7g\2\2\u01db\u01dc\7h\2\2\u01dc\u01dd\7q\2\2\u01dd")
        buf.write(u"\u01df\7t\2\2\u01de\u01d4\3\2\2\2\u01de\u01d6\3\2\2\2")
        buf.write(u"\u01de\u01db\3\2\2\2\u01dfh\3\2\2\2\u01e0\u01e1\7d\2")
        buf.write(u"\2\u01e1\u01e2\7t\2\2\u01e2\u01e3\7g\2\2\u01e3\u01e4")
        buf.write(u"\7c\2\2\u01e4\u01f4\7m\2\2\u01e5\u01e6\7e\2\2\u01e6\u01e7")
        buf.write(u"\7q\2\2\u01e7\u01e8\7p\2\2\u01e8\u01e9\7v\2\2\u01e9\u01ea")
        buf.write(u"\7k\2\2\u01ea\u01eb\7p\2\2\u01eb\u01ec\7w\2\2\u01ec\u01f4")
        buf.write(u"\7g\2\2\u01ed\u01ee\7t\2\2\u01ee\u01ef\7g\2\2\u01ef\u01f0")
        buf.write(u"\7v\2\2\u01f0\u01f1\7w\2\2\u01f1\u01f2\7t\2\2\u01f2\u01f4")
        buf.write(u"\7p\2\2\u01f3\u01e0\3\2\2\2\u01f3\u01e5\3\2\2\2\u01f3")
        buf.write(u"\u01ed\3\2\2\2\u01f4j\3\2\2\2\u01f5\u01f6\7v\2\2\u01f6")
        buf.write(u"\u01f7\7t\2\2\u01f7\u0205\7{\2\2\u01f8\u01f9\7e\2\2\u01f9")
        buf.write(u"\u01fa\7c\2\2\u01fa\u01fb\7v\2\2\u01fb\u01fc\7e\2\2\u01fc")
        buf.write(u"\u0205\7j\2\2\u01fd\u01fe\7h\2\2\u01fe\u01ff\7k\2\2\u01ff")
        buf.write(u"\u0200\7p\2\2\u0200\u0201\7c\2\2\u0201\u0202\7n\2\2\u0202")
        buf.write(u"\u0203\7n\2\2\u0203\u0205\7{\2\2\u0204\u01f5\3\2\2\2")
        buf.write(u"\u0204\u01f8\3\2\2\2\u0204\u01fd\3\2\2\2\u0205l\3\2\2")
        buf.write(u"\2\u0206\u020c\5\3\2\2\u0207\u020b\5\3\2\2\u0208\u020b")
        buf.write(u"\5\5\3\2\u0209\u020b\7a\2\2\u020a\u0207\3\2\2\2\u020a")
        buf.write(u"\u0208\3\2\2\2\u020a\u0209\3\2\2\2\u020b\u020e\3\2\2")
        buf.write(u"\2\u020c\u020a\3\2\2\2\u020c\u020d\3\2\2\2\u020dn\3\2")
        buf.write(u"\2\2\u020e\u020c\3\2\2\2\20\2v\u0080\u0089\u00b0\u0194")
        buf.write(u"\u01a3\u01a9\u01d2\u01de\u01f3\u0204\u020a\u020c\3\b")
        buf.write(u"\2\2")
        return buf.getvalue()


class JavaLexer(Lexer):

    atn = ATNDeserializer().deserialize(serializedATN())

    decisionsToDFA = [ DFA(ds, i) for i, ds in enumerate(atn.decisionToState) ]

    ESPACO = 1
    COMENTARIO = 2
    NUMERO = 3
    SHORT = 4
    BYTE = 5
    INT = 6
    LONG = 7
    CHAR = 8
    REAL = 9
    LOGICAL = 10
    NEW = 11
    PACK = 12
    IMPO = 13
    CONST = 14
    INST = 15
    GOTO = 16
    CLAS = 17
    ABST = 18
    FINA = 19
    PUBL = 20
    PRIV = 21
    PROT = 22
    EXTE = 23
    IMPL = 24
    STAT = 25
    THIS = 26
    SUPE = 27
    TRAN = 28
    VOLA = 29
    THROW = 30
    THROWS = 31
    VOID = 32
    SYNC = 33
    NATI = 34
    INTER = 35
    OPAT = 36
    OPAR = 37
    OPCO = 38
    EXDE = 39
    AC = 40
    FC = 41
    ACH = 42
    FCH = 43
    AP = 44
    FP = 45
    SIMBOLOS = 46
    PONTOV = 47
    CONDICAO = 48
    REPETICAO = 49
    INTERRUPCAO = 50
    EXCECAO = 51
    ID = 52

    channelNames = [ u"DEFAULT_TOKEN_CHANNEL", u"HIDDEN" ]

    modeNames = [ u"DEFAULT_MODE" ]

    literalNames = [ u"<INVALID>",
            u"'short'", u"'byte'", u"'int'", u"'long'", u"'char'", u"'boolean'", 
            u"'new'", u"'package'", u"'import'", u"'const'", u"'instanceof'", 
            u"'goto'", u"'class'", u"'abstract'", u"'final'", u"'public'", 
            u"'private'", u"'protected'", u"'extends'", u"'implements'", 
            u"'static'", u"'this'", u"'super'", u"'transient'", u"'volatile'", 
            u"'throw'", u"'throws'", u"'void'", u"'synchronized'", u"'native'", 
            u"'interface'", u"'['", u"']'", u"'{'", u"'}'", u"'('", u"')'", 
            u"';'" ]

    symbolicNames = [ u"<INVALID>",
            u"ESPACO", u"COMENTARIO", u"NUMERO", u"SHORT", u"BYTE", u"INT", 
            u"LONG", u"CHAR", u"REAL", u"LOGICAL", u"NEW", u"PACK", u"IMPO", 
            u"CONST", u"INST", u"GOTO", u"CLAS", u"ABST", u"FINA", u"PUBL", 
            u"PRIV", u"PROT", u"EXTE", u"IMPL", u"STAT", u"THIS", u"SUPE", 
            u"TRAN", u"VOLA", u"THROW", u"THROWS", u"VOID", u"SYNC", u"NATI", 
            u"INTER", u"OPAT", u"OPAR", u"OPCO", u"EXDE", u"AC", u"FC", 
            u"ACH", u"FCH", u"AP", u"FP", u"SIMBOLOS", u"PONTOV", u"CONDICAO", 
            u"REPETICAO", u"INTERRUPCAO", u"EXCECAO", u"ID" ]

    ruleNames = [ u"LETRA", u"DIGIT0", u"ESPACO", u"COMENTARIO", u"NUMERO", 
                  u"SHORT", u"BYTE", u"INT", u"LONG", u"CHAR", u"REAL", 
                  u"LOGICAL", u"NEW", u"PACK", u"IMPO", u"CONST", u"INST", 
                  u"GOTO", u"CLAS", u"ABST", u"FINA", u"PUBL", u"PRIV", 
                  u"PROT", u"EXTE", u"IMPL", u"STAT", u"THIS", u"SUPE", 
                  u"TRAN", u"VOLA", u"THROW", u"THROWS", u"VOID", u"SYNC", 
                  u"NATI", u"INTER", u"OPAT", u"OPAR", u"OPCO", u"EXDE", 
                  u"AC", u"FC", u"ACH", u"FCH", u"AP", u"FP", u"SIMBOLOS", 
                  u"PONTOV", u"CONDICAO", u"REPETICAO", u"INTERRUPCAO", 
                  u"EXCECAO", u"ID" ]

    grammarFileName = u"JavaLexer.g4"

    def __init__(self, input=None, output=sys.stdout):
        super(JavaLexer, self).__init__(input, output=output)
        self.checkVersion("4.7")
        self._interp = LexerATNSimulator(self, self.atn, self.decisionsToDFA, PredictionContextCache())
        self._actions = None
        self._predicates = None
