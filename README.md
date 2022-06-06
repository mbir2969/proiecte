# proiecte

Cerinta initiala a proiectului:

Organizatorii unui concurs de atletism pentru copii folosesc un sistem soft pentru înregistrarea participanților.
La diferite oficii din oraș se folosește sistemul. Persoana de la fiecare oficiu folosește o aplicație desktop cu
următoarele funcționalități:
1. Login. După autentificarea cu succes, o nouă fereastră se deschide în care sunt afișate grupele de vârstă (6-8
   ani, 9-11 ani, 12-15 ani) și probe (50m, 100m, 1000m și 1500m) la care se poate înscrie un copil. Pentru o
   anumită grupă de vârstă pot să fie disponibile doar o parte dintre probe (de exemplu, pentru grupa 6-8 ani un
   copil poate participa doar la probele de 50m si 100m).
2. Căutare. După autentificarea cu succes, persoana de la oficiu poate căuta copiii care s-au înscris deja la o
   anumită probă și o anumită grupă de vârstă. Aplicație afișează în altă listă/alt tabel toți copiii (numele
   copilului, vârsta și numărul de probe la care s-a înscris).
3. Înscriere. Un copil se poate înscrie la cel mult două probe. La înregistrare persoana de la oficiu introduce
   numele copilului, vârsta și probele la care vrea să participe. După o înscriere, toate persoanele de la celelalte
   oficii văd lista actualizată a probelor si numărul de copii care s-au înscris la fiecare probă.
4. Logout.

Proiectul are interfata grafica, jurnalizare, implementare pentru partea de client-server. De asemenea, 
contine servicii rest si un mic client web. Seviciile rest functioneaza atat cu clientul de test din folderul 
ServiciuRest/client, scris in Java, cat si cu clientul de test din folderul ClientCsharp,scris in C#.
