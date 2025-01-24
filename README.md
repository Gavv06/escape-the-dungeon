# escape-the-dungeon

controles:   
- flèche directionelles -> déplacements

enemis:   
- chaser-> suit le joueur   
- patrol-> suit un chemin précis

but: trouver la clé pour ouvrir la porte et sortir du donjon (ouverture de la porte non codé partie impossible a finir)   et éviter les énemis (contact = game over)

objet :   
- potion -> augmente la vitesse pendant 5sec (bug qui rend cette upgrade infini non patché)
- clé -> nécessaire pour finir le jeu

bug connus:      
- la generation de la carte a partir du txt est buggé est donne un resultat étrange   
- l'ajout des collision (non fini a temps) à cassé le code générant plus de 150 erreurs (pas eu le temps de patcher ça
