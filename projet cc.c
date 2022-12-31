#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 50
#define A 1000
typedef struct {
		int reference;
		char nom_produit[M];
		float prix;
		int stock;
		} objet;
void ajout_stock (objet t[], int *nbe, objet n_element)
{
	t[*nbe]=n_element;
	*nbe=*nbe+1;
	return;
}
int stock_plein (int nbe, int max)
{
	int test;
	test=0;
	if (nbe==max)
		{
			test= 1;
		}

	return test;
}
int VIDE (int nbe)
{
	int test;

	test=0;
	if (nbe == 0)
		{
			test = 1;
		}
	return test;
}
int ajout_s (objet t[], int nbe, int ref, int new_stock)
{
	int i=0,test=0;
	while (i < nbe && test == 0)
		{
			if (ref == t[i].reference)
				{
					t[i].stock=t[i].stock+new_stock;

					test = 1;
				}
			i=i+1;
		}
	return test;
}
int dim_s (objet t[], int nbe, int ref, int new_stock)
{
	int i=0,test=0;
	while (i < nbe && test == 0)
		{
			if (ref == t[i].reference)
				{
					t[i].stock=t[i].stock-new_stock;

					test = 1;
				}
			i=i+1;
		}
	return test;
}
int existe(objet t[],int *nbe,int ref)
{
     int test=0;
     int i=0;
     objet r;
    while(i<nbe)
    {
        if (t[i].reference == ref)
        {
            r=t[i];
            test=1;
            break;
        }
        else {i++;}
    }
    return test ;
}
objet cherche_objet(objet t[],int *nbe,int ref)
{
     int test=0;
     int i=0;
     objet r;
    while(i<nbe)
    {
        if (t[i].reference == ref)
        {
            r=t[i];
            test=1;
            break;
        }
        else {i++;}
    }
    if (test==1){return t[i] ;}
}

int supprime_stock (objet t[], int *nbe, int ref)
{
	int i, isup, test;


	i=0;
	test=0;
	while (i < *nbe && test == 0)
		{
			if (t[i].reference == ref)
				{
					test = 1;
					isup = i;
				}
			i=i+1;
		}

	if (test == 1)
		{
			i=isup;
			while (i < *nbe)
				{
					t[i]=t[i+1];
					i=i+1;

				}
				*nbe=*nbe-1;
		}
		else {printf("Cette reference ne correspond a aucun element dans votre stock\n\n");}



	return test ;
}
void affiche_tableau (objet t[], int nbe)
{
	int i;

	i=0;
	while (i < nbe)
	{
		printf("   Indice : %d \n",i);
		printf("Nom : %s\n",t[i].nom_produit);
		printf("Reference : %d\n",t[i].reference);
		printf("Prix : %.2f\n",t[i].prix);
		printf("Quantite : %d\n",t[i].stock);

		i=i+1;
	}
	return;
}
int main ()

{

    int jour, mois, annee;
	int i, choix, nbe=0, ajout_stk, ref, test,max,d,s;
	float valeur_stk;
	objet stock[A], element,H;




    while (choix != 7)
	{


		printf(" \n\n**<|>**<|>**<|>* GERER LE STOCK *<|>**<|>**<|>**\n\n");
		printf(" \nchoisir le parametre :\n");
		printf(" \n1 : Ajouter un produit au stock\n");
		printf("-----------------------------");
		printf("  \n2 : Modifier un produit du stock\n");
				printf("------------------------------");
		printf("  \n3 : Afficher le stock\n");
				printf("-------------------");
		printf("  \n4 : Supprimer un produit du stock\n");
				printf("-----------------------------");
		printf("  \n5 : Cherche un produit dans le stock\n");
				printf("----------------------------------");
		printf("  \n6 : Afficher l'historique d'entre et de sortie\n");
				printf("------------------------------------------");
		printf("  \n7 : Arreter le programme\n");
				printf("------------------------");
		printf("  \nQuel est votre choix ? : ");
		scanf("%d",&choix);

		if (choix > 0 && choix < 7)
		{
			if (choix == 1)
			{
				max=A;
				test=stock_plein(nbe,max);
				if (test == 0)
				{
					printf("\n\n*** Vous allez ajouter un nouvel produit au stock du magasin ***\n\n");
					printf("Donnez la reference : ");
					scanf("%d",&element.reference);
					printf("Donnez le nom de produit : ");
					scanf("%s",&element.nom_produit);
					fflush(stdin);

					printf("Donnez le prix unitaire HT : ");
					fflush(stdin);
					scanf("%f",&element.prix);
					fflush(stdin);
					printf("Donnez la quantite du stock : ");
					scanf("%d",&element.stock);
					fflush(stdin);

					do {
                    printf("Donnez l Annee : ");
                    fflush(stdin);
					scanf("%d",&annee);
                    }
					while (2022>annee );
					do {

					printf("Donnez le mois : ");
					fflush(stdin);
					scanf("%d",&mois);
					}
					while (mois>12 || 1>mois);
					do {
					fflush(stdin);
					printf("Aujourdhui c est le :  ");
					scanf("%d", &jour);
					fflush(stdin);}
					while (1>jour || jour>31);
					FILE *fichier;
					fichier = fopen("historique.txt", "a");

					if (fichier == NULL)
                    {
                     printf("Erreur ## l'historique est vide\n");
                     return 1;}

                     fprintf(fichier, "\nNom:%s",element.nom_produit);
                     fprintf(fichier, "  Refrence:%d",element.reference);
                     fprintf(fichier, "  Prix:%.3f",element.prix);
                     fprintf(fichier, "  Quantite:%d\n",element.stock);
                     fprintf(fichier, "date d ajout de produit %s au stock est: %d/",element.nom_produit, jour);
                     fprintf(fichier, "%d/",mois);
                     fprintf(fichier, "%d\n",annee);

                     fclose(fichier);
					ajout_stock(stock, &nbe, element);
				}
				else
				{
					printf(" \n\nCette action est impossible, le Stock est plein !");
				}

				FILE *fich;
					fich = fopen("stock.txt", "a");
					if (fich == NULL)
                    {
                     printf("Erreur ## le stock est vide\n");
                     return 1;}
                     fprintf(fich, "\nNom:%s",element.nom_produit);
                     fprintf(fich, "  Reference:%d",element.reference);
                     fprintf(fich, "  Prix:%.3f",element.prix);
                     fprintf(fich, "  Quantite:%d\n",element.stock);
                     fclose(fich);
				}
			if (choix == 2)
			{


			    char rep;
			    printf("vous voulez ajouter ou bien supprimer du stock ?"  );
			    printf("si vous allez ajoute choisir A sinon choisir S : ");
			    scanf("%s",&rep);
			    if(rep=='A'){
				printf("\n*** AJOUT AU STOCK ***\n\n");
				printf("Donnnez la reference du produit  : ");
				scanf("%d",&ref);
				printf("Donner la quantite a ajouter : ");
				scanf("%d",&ajout_stk);

				test=ajout_s(stock,nbe,ref,ajout_stk);
				if (test == 0)
				{
					printf("Une erreur ## cette reference n'existe pas");
				}
				else
				{
					do {
                    printf("Donnez l Annee : ");
                    fflush(stdin);
					scanf("%d",&annee);
                    }
					while (2022>annee);
					do {

					printf("Donnez le mois : ");
					fflush(stdin);
					scanf("%d",&mois);
					}
					while (mois>12 || 1>mois);
					do {
					fflush(stdin);
					printf("Aujourdhui c est le :  ");
					scanf("%d", &jour);
					fflush(stdin);}
					while (1>jour || jour>31);
					FILE *fichier;
					fichier = fopen("historique.txt", "a");
					objet ob=cherche_objet(stock,nbe,ref);
					if (fichier == NULL)
                    {
                     printf("Erreur ## l'historique est vide\n");
                     return 1;}
                     fprintf(fichier, "\nNom:%s",ob.nom_produit);
                     fprintf(fichier, "  Reference:%d",ob.reference);
                     fprintf(fichier, "  Prix:%.3f",ob.prix);
                     fprintf(fichier, "  Quantite:%d\n",ob.stock);
                     fprintf(fichier, "date dajout du produit %s au stock est: %d/",ob.nom_produit, jour);
                     fprintf(fichier, "%d/",mois);
                     fprintf(fichier, "%d\n",annee);
                     fclose(fichier);
					printf("le produit de reference %d a ete modifie ",ref);

				}}
				else{
				    printf("\n*** SUPRESSION DU STOCK ***\n\n");
				printf("Donnnez la reference de produit du STOCK : ");
				scanf("%d",&ref);
				printf("Donner la quantite a supprime: ");
				scanf("%d",&d);
				test=dim_s(stock,nbe,ref,d);
				if (test == 0)
				{
					printf("Une erreur ## cette reference n'existe pas");
				}
				else
				{
					do {
                    printf("Donnez l Annee : ");
                    fflush(stdin);
					scanf("%d",&annee);
                    }
					while (2022>annee);
					do {

					printf("Donnez le mois : ");
					fflush(stdin);
					scanf("%d",&mois);
					}
					while (mois>12 || 1>mois);
					do {
					fflush(stdin);
					printf("Aujourdhui c est le : ");
					scanf("%d", &jour);
					fflush(stdin);}
					while (1>jour || jour>31);
					FILE *fichier;
					fichier = fopen("historique.txt", "a");
					if (fichier == NULL)
                    {
                     printf("Erreur ## l'historique est vide\n");
                     return 1;}
                     fprintf(fichier, "\nNom:%s  ",element.nom_produit);
                     fprintf(fichier, "  Reference:%d  ",element.reference);
                     fprintf(fichier, "  Prix:%.3f  ",element.prix);
                     fprintf(fichier, "  Quantite:%d\n",element.stock);
                     fprintf(fichier, "La date de suppression de produit %s du stock est: %d/",element.nom_produit, jour);
                     fprintf(fichier, "%d/",mois);
                     fprintf(fichier, "%d\n",annee);
                     fclose(fichier);
					printf("Le produit de reference %d a ete modifie ",ref);


				}}
				remove("stock.txt");
                FILE *fich;
                fich = fopen("stock.txt", "a");
                int i=0;
                while (i < nbe)
                {
                fprintf(fich,"Nom:%s",stock[i].nom_produit);
                fprintf(fich,"  Reference:%d",stock[i].reference);
                fprintf(fich,"  Prix:%.2f",stock[i].prix);
                fprintf(fich,"  Quantite:%d\n",stock[i].stock);
                i=i+1;
                }
                 fclose(fich);
                }

			if (choix == 3)
            {
                  FILE *fichier = fopen("stock.txt", "r");
	        if (fichier == NULL) {
              printf("Erreur ## le stock est vide\n");
            return 1;}




            char ligne[A];
            while (fgets(ligne, sizeof(ligne), fichier))
            {
                printf("%s",ligne);
            }
             fclose(fichier);

            }
            if (choix == 4)
			{
                FILE *fichier;
                fichier = fopen("stock.txt", "a");
                if (fichier == NULL)
                {
                    printf("Erreur ## le stock est vide\n");
                }
				else
				{
					printf("\n\nConnaissez vous la reference du produit a supprimer ?\n");
					printf("0 : Oui, vous connaissez la reference du produit\n");
					printf("1 : Non, vous ne connaisez pas la reference du produit\n");
					printf("Alors ? ");
					scanf("%d",&s);
					if (s == 0)
					{
						printf("Entrer la reference du produit a supprimer : ");
						scanf("%d",&ref);

						int k=supprime_stock(stock,nbe,ref);

					}
					else if ( s == 1)
					{
						printf("\n\nVous devriez afficher le contenu du stock\n");
						printf("Puis noter la reference du produit a supprimer\n\n");
					}

				}}
            if (choix == 5)
			{
			     printf("donner la reference du produit a cherche dans le stock: ");
			     scanf("%d",&ref);
			     int exist=existe(stock,nbe,ref);
			if (exist==0)
            {
                printf("le prouit n'existe pas dans le stock\n\n");

            }
            else
            {
                objet a=cherche_objet(stock,nbe,ref);
                printf("le produit cherchee est %s de reference %d ,de prix  %.3f  et de quantitee dans le stock %d\n",a.nom_produit,a.reference,a.prix,a.stock);

            }
            }
			 if (choix==6)
             {
                 FILE *fichier = fopen("historique.txt", "r");
	        if (fichier == NULL) {
              printf("Erreur ## l'historique est vide\n");
            return 1;}




            char ligne[A];
            while (fgets(ligne, sizeof(ligne), fichier)) {
                    printf("%s",ligne);
             }
             fclose(fichier);
             }



			if (choix == 7)
			{
				printf("\n\n Vous venez de fermer votre STOCK    ");
				printf(" \n**<|>**<|>**<|>* AU REVOIR **<|>**<|>**<|>*\n");

			}}


	}
	return 0;
}
