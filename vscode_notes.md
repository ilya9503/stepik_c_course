# Инструкция по настройке среды VSCode для языков С/С++
 - Открыть терминал в VSCode:
	- CTRL + ~
 - Запускаем программу в терминале:
	- g++ test_cpp.cpp
	- .\a.exe
 - Перекомпиляция программы:
	- CTRL + Shift + B
 - Прописать для компилятора флаг используемого стандарта:
	- .vscode --> tasks.json --> args --> "-std=c99" для С и для С++ "-std=c++14"
 - Прописать для утилиты coderunner флаг используемого стандарта:
	- File --> Preferences --> Settings --> User --> "code runner run in terminal" галочка
	- File --> Preferences --> Settings --> Workspace --> "code runner run in terminal" галочка
	- File --> Preferences --> Settings --> Workspace --> "Run Code Configuration" --> Code-runner: Executor Map
	- Содержимое добавится в .vscode --> settings.json
	- Редактируем для "c" и для "cpp" те же ключи, что и для компилятора

# Определения
- gcc(GNU Compiler Collections) - компилятор для языка С 
- g++ - компилятор для языка С++
- gdb(gnu project debugger) - отладчик для программ на языке С и С++
- Отладчик - это программа, которая выполняет внутри себя другую программу