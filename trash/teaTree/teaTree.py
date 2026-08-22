#	teaTree // ☭
# MichiTheCat-RedStar (c) 2026

from pathlib import Path

def makeTree():
	mainPath = Path(input('Введите путь или относительный путь:\n').strip())
	
	if not mainPath.exists(): # йцукен не пройдёт, только реальные пути!
		raise ValueError('Нет такого пути!')
	elif not mainPath.is_dir(): # Файлы не папки
		raise ValueError('Указана не папка!')
	
	rec_level = 0
	def look(name, rec):
		nonlocal rec_level
		for child in name.iterdir():
			
			part_buffer = [x for x in child.parts]
			for content in range(len(part_buffer)):
				if part_buffer[content] == part_buffer[-2]:
					part_buffer[content] = '├╴'
				elif part_buffer[content] != part_buffer[-1]:
					part_buffer[content] = '│ '
			print(''.join(part_buffer))
			# СТОП-ФЛАГ!!!
			# Мой способ неправильный, нужно возвращаться к идеи буффера
			# и представлять либо в виде 2D массива, чтобы иметь предс-
			# тавление о строке следующей, либо вообще сделать иначе и
			# использовать rec_level, уровень рекурсии, чтобы понять как
			# глубока кролячья нора.. Писать код в час ночи было ошибкой
			
			if child.is_dir():
				rec_level += 1
				#path_buffer.append((child, 'folder'))
				look(child, rec)
				rec_level -= 1
			else:
				...
				#path_buffer.append((child, 'file'))
	look(mainPath, rec_level)

if __name__ == '__main__':
	makeTree()
	# Я теперь программирую в ФП?
