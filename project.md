# Budget tracker
## Popis
- Program bude slouzit k ukladani, zobrazovani a upravovani utrat uzivatele
- Uzivatel si bude moct nastavit napr. tydenni rozpocet
    - Pak se mu ukaze zbyvajici rozpocet na zbytek tydne
- Uzivatel si prida polozku: nazev, pocet, cena za kus, datum
- Program bude umet vytvorit vizualizaci utrat
    - Ktere polozky staly nejvic na kus nebo komplet
- Zobrazeni utrat oproti minulemu tydnu

### Extra
- Moznost davat zaznamy do kategorii
- Moznost aktivovat trvaly prikaz - kazdych x dnu / tydnu / mesicu se vytvori novy zaznam podle sablony
- Barvicky

## Technologie
- Pro kompilaci se bude pouzivat CMake
- Aplikace bude napsana v jazyce C++, uzivatelske rozhrani bude udelane pomoci `ncurses`
    - Vizualizace dat bude taky generovana v `ncurses`
- Data o utratach budou ulozene v databazi pomoci `sqlite`
- Nebude se zapisovat nic do disku, ulozeni probehne az pri ukonceni programu pres 'Exit' na hlavni nabidce

## Uzivatelske rozhrani
- Po spusteni a nahrani databazoveho souboru se zobrazi hlavni nabidka (rozcestnik)
    1. Zobrazit vsechny utraty *(vypis)*
    2. Pridat utratu
    3. Editovaci mod - podle `id` bude jeden zaznam upraven
    4. Vytvorit vizualizaci (asi histogram)
    5. Tydenni zprava *(mesicni? denni?)*
        - Za co bylo nejvice utraceno tento *{mesic | tyden}* treba
    6. Save & exit
    :q
