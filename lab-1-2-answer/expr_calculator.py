'''Expression recognizer.
Handles expression described in expr.g4.
Grammar file should be compiled by antlr4 with option '-Dlanguage=Python3' before executing this.
Module 'antlr4' is required.
'''
import antlr4
import AddFirstLexer
import AddFirstParser
import AddFirstListener
import MultFirstLexer
import MultFirstParser
import MultFirstListener
from typing import Mapping


class MultListener(MultFirstListener.MultFirstListener):
    '''Listener doing calculation based on recognized input.
    '''

    def __init__(self, var_value_source: Mapping[str, int]):
        self.var_value_source = var_value_source

    # def enterNumber(self, ctx:AddFirstParser.AddFirstParser.NumberContext):
    #     print('(')
    
    # def enterMult(self, ctx:AddFirstParser.AddFirstParser.MultContext):
    #     print('(')

    def exitMult(self, ctx: MultFirstParser.MultFirstParser.MultContext):
        ctx.value = '('+str(ctx.getChild(0).value) +'*'+ str(ctx.getChild(2).value)+')'
        ctx.haha = 'just for test'

    def exitNumber(self, ctx: MultFirstParser.MultFirstParser.NumberContext):
        ctx.value = str(ctx.getChild(0))


    def exitPlus(self, ctx: MultFirstParser.MultFirstParser.PlusContext):
        ctx.value = '('+str(ctx.getChild(0).value)+'+' + str(ctx.getChild(2).value)+')'

class AddListener(AddFirstListener.AddFirstListener):
    '''Listener doing calculation based on recognized input.
    '''

    def __init__(self, var_value_source: Mapping[str, int]):
        self.var_value_source = var_value_source

    # def enterNumber(self, ctx:AddFirstParser.AddFirstParser.NumberContext):
    #     print('(')
    
    # def enterMult(self, ctx:AddFirstParser.AddFirstParser.MultContext):
    #     print('(')

    def exitMult(self, ctx: AddFirstParser.AddFirstParser.MultContext):
        ctx.value = '('+str(ctx.getChild(0).value) +'*'+ str(ctx.getChild(2).value)+')'
        ctx.haha = 'just for test'

    def exitNumber(self, ctx: AddFirstParser.AddFirstParser.NumberContext):
        ctx.value = str(ctx.getChild(0))


    def exitPlus(self, ctx: AddFirstParser.AddFirstParser.PlusContext):
        ctx.value = '('+str(ctx.getChild(0).value)+'+' + str(ctx.getChild(2).value)+')'

class LazyInputDict(dict):
    '''A lazy dictionary asking for input when a new item is queried.'''

    def __getitem__(self, key):
        try:
            return dict.__getitem__(self, key)
        except KeyError:
            self[key] = int(
                input('Please enter value for variable \'{}\': '.format(key)))
        return dict.__getitem__(self, key)



if __name__ == '__main__':
    ADD_PARSER = AddFirstParser.AddFirstParser(antlr4.CommonTokenStream(AddFirstLexer.AddFirstLexer(
        antlr4.FileStream('test_left_recursive.c1'))))
    ADD_PARSER.addParseListener(AddListener(LazyInputDict()))
    MULT_PARSER = MultFirstParser.MultFirstParser(antlr4.CommonTokenStream(MultFirstLexer.MultFirstLexer(
        antlr4.FileStream('test_left_recursive.c1'))))
    MULT_PARSER.addParseListener(MultListener(LazyInputDict()))
    print('Test the behaviour of AddFirst Parser')
    print(ADD_PARSER.e().value)
    print('Test the behaviour of MultFirst Parser')
    print(MULT_PARSER.e().value)
