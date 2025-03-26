gestion_etudiant:fonction_yebga.h fonction_yebga.c main_yebga.c
	gcc -o gestion_etudiant fonction_yebga.c main_yebga.c
run:
	./gestion_etudiant
clean:
	rm -f gestion_etudiant
