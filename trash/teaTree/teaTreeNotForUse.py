import subprocess
result = subprocess.run(['tree', '../../'], capture_output=True, text=True)
output = result.stdout
output = output.replace('../../', '.')
output = output.replace('└── ', '└╴')
output = output.replace('├── ', '├╴')
output = output.replace('    ', '  ')
output = output.replace('│   ', '│ ')
print(output)
