# Курсовая работа по МПС Смородина М.В.
Смородина М.В. ИУ6-74Б

Курсовая по МПС 2023.  
<b>Тема</b>: Модуль для хэширования данных  
  
<b>Техническое задание:</b>  
&emsp;Разработать МК-систему для хэширования данных. Обеспечить оператору возможность  
выбора алгоритма хэширования (crc, md, sha). Для каждого алгоритма хэширования  
определить ключевые метрики.  
&emsp;Предусмотреть возможность ввода данных с ПЭВМ и телефона. Обеспечить передачу  
зашифрованных данных и сопутствующей информации в ПЭВМ.  
&emsp;Результаты выполнения команд и сообщения об ошибках выводить на ЖК-дисплей.  
&emsp;Выбрать наиболее оптимальный вариант МК. Выбор обосновать.  
&emsp;Разработать схему, алгоритмы и программу. Отладить проект в симуляторе или на макете.  
Оценить потребляемую мощность. Описать принципы и технологию программирования  
используемого микроконтроллера.

# Компоненты
Микроконтроллер: STM32F103C8  
ЖК-дисплей: LM016L  
3 кнопки (для выбора способа хэишрования: crc, md, sha) и 1 кнопка выбора порта ввода (ПЭВМ или телефон)  
USB-UART преобразователь FT232R  
AU-Y1005-R usb drive

# Алгоритмы
В качестве реализациии sha выбран алгоритм SHA-2 (SHA-256)

В качестве реализации md выбран алгоритм MD-5

В качестве реализации crc выбран CRC-16  

# Демонстрация  
Для демонстрации работы программы используются Proteus 8.13  
Для демонстрации работы USB используется TerminalTMB v3 (COM7, 115200, 7, even, 1)  
Для демонстрации работы UART используется Virtual Terminal в Proteus
