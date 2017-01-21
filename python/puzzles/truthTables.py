def bitwiseAnd(a, b):
    return a & b

def bitwiseOr(a, b):
    return a | b

def bitwiseXor(a, b):
    return a ^ b

table = {
    '&': {
        'text': 'AND',
        'fn': bitwiseAnd
    },
    '|': {
        'text': 'OR',
        'fn': bitwiseOr
    },
    '^': {
        'text': 'XOR',
        'fn': bitwiseXor
    }
}

def makeTruthTable(operator):
    print('\n---------------------------------------------\n')
    print('Bitwise', table[operator]['text'])
    print()

    for i in range(0, 4):
        bit_a = int((i & 2) / 2)
        bit_b = i & 1
        print('\t', bit_a, operator, bit_b, '=>', table[operator]['fn'](bit_a, bit_b))

def main():
    makeTruthTable('&')
    makeTruthTable('|')
    makeTruthTable('^')

if __name__ == '__main__':
    main()

