# projects

Project's initial requirements:

The organizers of a children's athletics competition use a software system for participant registration. The system is used at various offices throughout the city. Each office personnel uses a desktop application with the following functionalities:

1. **Login:** After successful authentication, a new window opens displaying age groups (6-8 years, 9-11 years, 12-15 years) and events (50m, 100m, 1000m, and 1500m) where a child can enroll. Only a subset of events may be available for a specific age group (for example, children aged 6-8 can only participate in the 50m and 100m events).

2. **Search:** After successful authentication, office personnel can search for children who have already registered for a specific event and age group. The application displays in another list/table all children (child's name, age, and the number of events they have enrolled in).

3. **Enrollment:** A child can enroll in a maximum of two events. During registration, office personnel enter the child's name, age, and the events they want to participate in. After enrollment, all personnel from other offices see the updated list of events and the number of children enrolled in each event.

4. **Logout:** Allows the user to log out.

The project has a graphical interface, logging, client-server implementation, and includes REST services and a small web client. The REST services work with both the test client in the ServiciuRest/client folder, written in Java, and the test client in the ClientCsharp folder, written in C#.

Proiectul are interfata grafica, jurnalizare, implementare pentru partea de client-server. De asemenea, 
contine servicii rest si un mic client web. Seviciile rest functioneaza atat cu clientul de test din folderul 
ServiciuRest/client, scris in Java, cat si cu clientul de test din folderul ClientCsharp,scris in C#.
