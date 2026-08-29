Попытки и тесты создать своё ядро


Обратитесь к папке ./src/ или ./src/readme.md


Представление дерева файлов:
.
├╴license.txt
├╴readme.txt
├╴roadmap.txt
├╴src
│ ├╴boot.asm
│ ├╴kernel.c
│ ├╴linker.ld
│ ├╴readme.md
│ └╴tealibs
│   ├╴teavideo.c
│   └╴teavideo.h
└╴trash
  ├╴helps.txt
  ├╴mylibc
  │ ├╴License.txt
  │ └╴ReadMe.txt
  ├╴readme.txt
  ├╴teaTree
  │ ├╴License.txt
  │ ├╴ReadMe.txt
  │ ├╴teaTreeNotForUse.py
  │ └╴teaTree.py
  └╴tests
    ├╴images
    │ ├╴test0.png
    │ ├╴test11.jpg
    │ ├╴test1.png
    │ ├╴test2-0.jpg
    │ ├╴test2-1.jpg
    │ ├╴test3.jpg
    │ ├╴test4.png
    │ ├╴test5.jpg
    │ ├╴test6.jpg
    │ ├╴test8.png
    │ └╴test9.png
    ├╴test0
    │ ├╴boot.asm
    │ └╴readme.txt
    ├╴test1
    │ ├╴boot.asm
    │ └╴readme.txt
    ├╴test10
    │ ├╴boot.asm
    │ ├╴build.bat
    │ ├╴kernel.c
    │ ├╴linker.ld
    │ ├╴Makefile
    │ ├╴readme.txt
    │ └╴tealibs
    │   ├╴readme.txt
    │   ├╴teaio.h
    │   ├╴teakeyboard.c
    │   ├╴teakeyboard.h
    │   ├╴teaprint.c
    │   ├╴teaprint.h
    │   ├╴teavideo.c
    │   └╴teavideo.h
    ├╴test11
    │ ├╴boot.asm
    │ ├╴iso
    │ │ └╴teaKernel.iso
    │ ├╴kernel.c
    │ ├╴linker.ld
    │ ├╴Makefile
    │ ├╴readme.txt
    │ └╴tealibs
    │   ├╴readme.txt
    │   ├╴teaio.h
    │   ├╴teakeyboard.c
    │   ├╴teakeyboard.h
    │   ├╴teaprint.c
    │   ├╴teaprint.h
    │   ├╴teavideo.c
    │   └╴teavideo.h
    ├╴test12 (test2-j)
    │ ├╴boot.asm
    │ ├╴kernel.c
    │ ├╴kernel.elf
    │ ├╴linker.ld
    │ └╴readme.txt
    ├╴test13
    │ ├╴boot.asm
    │ ├╴kernel.c
    │ ├╴linker.ld
    │ ├╴Makefile
    │ ├╴readme.txt
    │ └╴tealibs
    │   ├╴readme.txt
    │   ├╴teaio.h
    │   ├╴teakeyboard.c
    │   ├╴teakeyboard.h
    │   ├╴teaprint.c
    │   ├╴teaprint.h
    │   ├╴teavideo.c
    │   └╴teavideo.h
    ├╴test2
    │ ├╴boot.asm
    │ ├╴kernel.c
    │ ├╴linker.ld
    │ └╴readme.txt
    ├╴test3
    │ ├╴boot.asm
    │ ├╴kernel.c
    │ ├╴linker.ld
    │ └╴readme.txt
    ├╴test4
    │ ├╴boot.asm
    │ ├╴kernel.c
    │ ├╴linker.ld
    │ ├╴readme.txt
    │ └╴tealibs
    │   ├╴teavideo.c
    │   └╴teavideo.h
    ├╴test5
    │ ├╴boot.asm
    │ ├╴kernel.c
    │ ├╴linker.ld
    │ ├╴Makefile
    │ ├╴readme.txt
    │ └╴tealibs
    │   ├╴teaprint.c
    │   ├╴teaprint.h
    │   ├╴teavideo.c
    │   └╴teavideo.h
    ├╴test6
    │ ├╴boot.asm
    │ ├╴kernel.c
    │ ├╴linker.ld
    │ ├╴Makefile
    │ ├╴readme.txt
    │ └╴tealibs
    │   ├╴teaprint.c
    │   ├╴teaprint.h
    │   ├╴teavideo.c
    │   └╴teavideo.h
    ├╴test7
    │ ├╴boot.asm
    │ ├╴build.bat
    │ ├╴kernel.c
    │ ├╴linker.ld
    │ ├╴Makefile
    │ ├╴readme.txt
    │ └╴tealibs
    │   ├╴teaprint.c
    │   ├╴teaprint.h
    │   ├╴teavideo.c
    │   └╴teavideo.h
    ├╴test8
    │ ├╴boot.asm
    │ ├╴build.bat
    │ ├╴kernel.c
    │ ├╴linker.ld
    │ ├╴Makefile
    │ ├╴readme.txt
    │ └╴tealibs
    │   ├╴teaio.h
    │   ├╴teaprint.c
    │   ├╴teaprint.h
    │   ├╴teavideo.c
    │   └╴teavideo.h
    └╴test9
      ├╴boot.asm
      ├╴build.bat
      ├╴kernel.c
      ├╴linker.ld
      ├╴Makefile
      ├╴readme.txt
      └╴tealibs
        ├╴teaio.h
        ├╴teakeyboard.c
        ├╴teakeyboard.h
        ├╴teaprint.c
        ├╴teaprint.h
        ├╴teavideo.c
        └╴teavideo.h



Лицензия: GNU GENERAL PUBLIC LICENSE
Автор: MichiTheCat-RedStar (c) 2026
