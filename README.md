## MyIRC - Projet scolaire

Réalisation d'un serveur et d'un client IRC respectant la norme RFC1459

**Fonctionnement :**
- Le serveur :
```
./serveur <port>
      port : nombre compris entre 0 et 65000
```

- Le client :
```
./client <ip_address> <port>
      ip_address : Adresse IP de l'hote du serveur
      port : Port d'écoute du serveur
```

**Commandes du client :**

- Joindre une salle de chat : ```/join <room>```
- Quitter une salle de chat : ```/part <room>```
- Quitter le serveur IRC : ```/quit```
- Changer de pseudo : ```/nick <pseudo>```
- Lister les utilisateurs : ```/names <room>```
- Envoyer un message privé : ```/msg <utilsateurs>```
