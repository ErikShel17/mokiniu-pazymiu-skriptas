# 📚 Mokinių pažymių valdymo sistema (C++)

Ši programa leidžia vartotojui valdyti mokinių sąrašą ir jų pažymius naudojant paprastą konsolinį meniu.

## 🔧 Funkcionalumas

Programa leidžia:

- ➕ Įvesti mokinių vardus ir jų pažymius  
- 📋 Peržiūrėti visų mokinių pažymius  
- 🔍 Peržiūrėti konkretaus mokinio pažymius  
- ✏️ Atnaujinti konkretų pažymį  
- ❌ Pašalinti mokinį iš sąrašo  

## 🗂 Duomenų struktūra

Programa naudoja:

- `string vardai[100]` – saugo iki 100 mokinių vardų  
- `int pazymiai[100][10]` – saugo iki 10 pažymių kiekvienam mokiniui  

> Pastaba: pažymys `0` reiškia, kad vieta tuščia (naudojama kaip pabaigos žymeklis).