# Radix Sort

**Radix Sort ordina numeri per posizione delle cifre, iniziando dalla cifra meno significativa (unità) alla più significativa (decine, centinaia, ecc.). Utilizza un ordinamento stabile come il Counting Sort per ogni posizione, garantendo un ordinamento corretto ed efficiente.**

## Counting Sort: Spiegazione Semplice
Counting Sort è un algoritmo di ordinamento che ordina gli elementi contando il numero di occorrenze di ciascun valore unico nell'array. È particolarmente efficace quando l'intervallo dei valori è limitato.

## Come Funziona
Trova il valore massimo nell'array per determinare l'intervallo.
Crea un array di conteggio con lunghezza pari al valore massimo + 1.
Conta le occorrenze di ciascun valore nell'array di input e memorizza queste conte in corrispondenza dell'indice del valore nell'array di conteggio.
Calcola le posizioni cumulative nell'array di conteggio.
Costruisci l'array ordinato scorrendo l'array di input in ordine inverso e posizionando ciascun elemento nella sua posizione corretta basata sull'array di conteggio.

