```c
/* Таблица кириллицы*/
char str_str[] =
"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"
"абвгдеёжзийклмнопрстуфхцчшщъыьэюя";

char str_arr[][2] = {
    "\x41","\xA0","\x42","\xA1","\xE0","\x45","\xA2","\xA3","\xA4","\xA5",
    "\xA6","\x4B","\xA7","\x4D","\x48","\x4F","\xA8","\x50","\x43","\x54",
    "\xA9","\xAA","\x58","\xE1","\xAB","\xAC","\xE2","\xAD","\xAE","\x62",
    "\xAF","\xB0","\xB1","\x61","\xB2","\xB3","\xB4","\xE3","\x65","\xB5",
    "\xB6","\xB7","\xB8","\xB9","\xBA","\xBB","\xBC","\xBD","\x6F","\xBE",
    "\x70","\x63","\xBF","\x79","\xE4","\x78","\xE5","\xC0","\xC1","\xE6",
    "\xC2","\xC3","\xC4","\xC5","\xC6","\xC7"
};

/* Рабочий буфер для RuChar */
char RuChar_buf[64];

char* RuChar(const char *s)
{
    RuChar_buf[0] = '\0';

    for (size_t i = 0; s[i] != '\0'; i++) {
        char *pos = strchr(str_str, s[i]);
        if (pos) {
            int idx = (int)(pos - str_str);
            /* проверяем наличие места (добавляем 2 байта) */
            if (strlen(RuChar_buf) + 2 < sizeof(RuChar_buf)) {
                strcat(RuChar_buf, str_arr[idx]);
            } else {
                break; /* не влезает — выходим */
            }
        } else {
            /* символ не найден в таблице: копируем как есть, если есть место */
            size_t len = strlen(RuChar_buf);
            if (len + 1 < sizeof(RuChar_buf)) {
                RuChar_buf[len]   = s[i];
                RuChar_buf[len+1] = '\0';
            } else {
                break;
            }
        }
    }
    return RuChar_buf;
}

```
