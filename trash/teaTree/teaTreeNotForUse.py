import subprocess
result = subprocess.run(['tree', '../../'], capture_output=True, text=True)
output = result.stdout
output = output.replace('../../', '.')
output = output.replace('└── ', '└╴')
output = output.replace('├── ', '├╴')
output = output.replace('    ', '  ')
output = output.replace('│   ', '│ ')
print(output)
input()

# Уж если я работаю по принципу "Работает - не трогай" и не переписываю нормально, то хотя бы автоматизировать, чтобы вместо вывода перезаписовало ../../tree.txt, вставляя текст по умолчанию, а снизу уже дерево
