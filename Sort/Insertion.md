# Insertion

**Ordina gli elementi in O(n²)**

### **Loop principale:**
Percorre l'array finchè non trova un elemento più piccolo del precedente.
Ripeti fino alla fine dell'array.

L'Elemento minore trovato, va salvato in una temporanea per essere valutato nel loop secondario.

### **Loop secondario:**
Partendo dalla posizione dell'loop principale SCORRO all'Indietro (finchè [while]) non siamo all'index 0 o finchè il temporaneo non è maggiore dell'elemento attuale.
**CHE INFORMAZIONI ABBIAMO? Sappiamo che* tutti gli elementi precedenti all'elemento in temporanea sono GIà ORDINATI.**
**GRAZIE AL: "Percorre l'array finchè non trova un elemento più piccolo del precedente." del loop1**
Durante il loop, se la temporanea rimane minore l'elemento successivo andrà a coprire il posto attuale.
Uscito da questo loop e quindi avendo trovato lo **0 index o l'elemento maggiore** dell'elemento in temporanea, si va a sostituire l'elemento dell'attuale posizione di loop con l'elemento temporaneo.

## SE:

**1 3 4 5 2**

Primo loop si ferma al **2** cioè l'ultimo elemento.
Da li 2 verrà salvato in una temporanea e inizia il secondo loop dove:

dalla posizione "attuale" (in questo caso l'ultima) valuto il **2** con il **5**,
è 5 inferiore di 2? **No.**
allora sposto il 5 in avanti cioè diventa:
**1 3 4 5 5**

scendo di uno, dalla posizione "attuale" valuto il **2** con il **4**
ripeto la domanda:
è 4 inferiore a **2**? No.

**1 3 4 4 5**

Fino ad arrivare alla posizione del 2 correttamente dove finalmente lo inserisco, 
sapendo che il numero attuale è un posto vacante o duplice di quello successivo.

Finendo con 
**1 2 3 4 5**

```c
void insertionSort(int *arr, int n)
{
	int i, key, *j;
	for (i = 1; i < n; i++)
	{
		key = *(arr + i); //salvo in temporanea
		j = arr + i - 1;
		while (j >= arr && *j > key)
		{
			*(j + 1) = *j; // sposto l'attuale avanti o meglio dire lo copio
			j--;
		}
		*(j + 1) = key; // Inserisce l'elemento nella posizione corretta
	}
}
```