#	teaTree // ☭
# MichiTheCat-RedStar (c) 2026

from pathlib import Path

def makeTree(path: str, dotpath=True) -> None:
	mainPath = Path(path)
	
	# Проверяю на нарущение условий
	if not mainPath.exists(): # йцукен не пройдёт, только реальные пути!
		raise ValueError('Нет такого пути!')
	elif not mainPath.is_dir(): # Файлы не папки
		raise ValueError('Указана не папка!')
	
	# Рекурсивный спуск и создание списка с (имя, уровень_рекурсии)
	tree, rec_index = [('.', 0)], 1 # 0 специально '.', а не mainPath!
	def look(path):
		nonlocal rec_index
		for child in path.iterdir():
			if child.is_dir():
				tree.append((f'{child.name}/', rec_index))
				rec_index += 1
				look(child)
				rec_index -= 1
			else:
				tree.append((f'{child.name}', rec_index))
	look(mainPath)
	
	if not tree:
		return
	if not dotpath: # Ладно, передумал
		tree[0] = (str(mainPath), 0)
	
	# Создание дерева на основе списка
	rec_index = 0 # Теперь указывает на "Актуальный" индекс для сверения <- Бесполезно?
	for child_index in range(len(tree)): # '└╴', '├╴', '  ', '│ '
		child_name, child_rec = tree[child_index] # для удобства
		
		# Работа с телом
		print('│ '*(child_rec-1), end='')								# <- TODO + сделать argv путь и перенаправление stdin
		
		# Работа с хвостом
		if child_index+1 < len(tree): # чтобы не выйти в IndexError
			if tree[child_index+1][1] < child_rec:
				print('└╴', end='')
			elif child_index != 0:
				print('├╴', end='')
		else:
			print('└╴', end='')
		
		print(child_name)

if __name__ == '__main__':
	print('MichiTheCat-RedStar - teaTree - MIT license (c) 2026.')
	makeTree(input('Введите относительный путь: ').strip())
	# Я теперь программирую в ФП?
