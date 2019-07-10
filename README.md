# Mini_Merto
game project (with Kacper Grzesiak)

Chcielibyśmy zrealizować projekt gry Mini Metro ( mechanika oraz próbna wersja do zagrania jest dostępna w linku),
na Youtube jest również sporo game play'i z tej gry, więc łatwo jest zrozumieć zasadę jej działania.

https://dinopoloclub.com/minimetro/

na samym początku chcielibyśmy skupić się na podstawowych mechanikach rozgrywki, później dodając bardziej skomplikowane rzeczy w miarę naszych możliwości.

Podstawowa mechanika rozgrywki:
- pojawianie się stacji o różnych kształtach w losowych miejscach (nie za blisko innych stacji),
- pojawianie się pasażerów na stacjach o różnych kształtach (chcących dojechać na stacje z oznaczoną określoną figurą),
- łączenie stacji w linie i ich tworzenie, modyfikowanie oraz kursujące po nich kolejki zabierające pasażerów,
- upływający czas oraz co tygodniowe bonusy (w postaci dodatkowych kolejek i linii),
- z czasem zwiększenie ilości pojawiających się pasażerów i stacji,
- gra kończy się gdy któraś ze stacji nie zostanie obsłużona a i jest przeludniona (np czeka na niej 10 pasażerów)

Klasy:
- cKolejka - jeżdżąca po liniach charakterystycznego dla siebie koloru i zabierająca oraz wysadzająca pasażerów na odpowiednich stacjach,
- cStacja - odpowiada za pojawianie się na niej pasażerów, przechowuje swój kształt i sprawdza warunek zakończenia gry (10ciu pasażerów na 1 stacji - przeludnienie),
- cLinia - przechowuje wszystkie stacje przez jakie przechodzi, kolor oraz czy jest linią czy pętlą i kolejka może jeździć do okoła,
- cDraw_Line, cDraw_Station, cDraw_Locomotive - odpowiadają za graficzną reprezentację oraz przetwarzają dane do formy w której mogą zostać przekazane do wyżej wymienionych klas.

