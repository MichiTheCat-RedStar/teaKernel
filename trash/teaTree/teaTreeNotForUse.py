import subprocess
result = subprocess.run(['tree', '../../'], capture_output=True, text=True)
output = result.stdout
output = output.replace('../../', '.')
output = output.replace('└── ', '└╴')
output = output.replace('├── ', '├╴')
output = output.replace('    ', '  ')
output = output.replace('│   ', '│ ')
output = output.split('\n')
del output[-3:]
output = '\n'.join(output)
print(output)

with open('../../tree.txt', 'w', encoding='utf-8') as f:
	f.write('Тут представлено дерево всех файлов и папок для удобства:\n\n'+output)
# input()

# Уж если я работаю по принципу "Работает - не трогай" и не переписываю нормально, то хотя бы автоматизировать, чтобы вместо вывода перезаписовало ../../tree.txt, вставляя текст по умолчанию, а снизу уже дерево
#  ^ Готово
