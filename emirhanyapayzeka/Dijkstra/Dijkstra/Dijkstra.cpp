#include "stdafx.h"
#include <stdio.h>
#include <limits.h>


// Graftaki d���m say�s�n� V global de�i�keni ile ifade edece�iz.
#define V 9

//En k�sa yolu bulan yard�mc� fonksiyon.
//Ziyaret edilmemi� d���mler i�erisindeki en k�sa maliyetli d���m� return ediyor.
int minDistance(int dist[], bool sptSet[])
{
    //�lk ba�ta Sonsuz de�er at�yoruz.
    int min = INT_MAX, min_index;
    //A�a��daki d�ng� ziyaret edilmemi� d���mler i�erisinde min de�erinden daha k���k
    //d���mleri tespit ediyor. En k�����n� buluyor.
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    //En k���k d���m�n indexini return ediyoruz.
    return min_index;
}

// Ba�lang�� noktas�ndan di�er d���mlere olan maliyeti yazd�ran fonksiyon.
int printSolution(int dist[], int n)
{
    printf("Dugumlerin ana kayna�a olan uzakligi");
    for (int i = 0; i < V; i++)
        printf("%d tt %dn", i, dist[i]);
}

// Dijkstra algoritmas�n�n temel fonksiyonu
// A��rl�kl� graf yap�m�z� graph[V][V] dizisinde tutuyoruz
// int src ise ba�lang�� noktam�z.
void dijkstra(int graph[V][V], int src)
{
    int dist[V];     //Ba�lang�� d���m�nden bir ba�ka d���me olan uzakl��� burada tutaca��z.

    bool sptSet[V];  //D���m ziyaret edildi�inde bu diziye aktar�yoruz. B�ylece ziyaret edilmi� d���mleri kontrol edebilece�iz.


    //�lk ba�ta T�m d���mleri ziyaret edilmemi� olarak i�aretliyoruz.
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    //Ba�lang�� noktas�n�n maliyeti her zaman s�f�r olur.
    dist[src] = 0;

    // T�m d���mlere olan uzakl���n (kaynaktan) bulunaca�� d�ng�ye giri� yap�yoruz.
    for (int count = 0; count < V - 1; count++)
    {
        // Hen�z ziyaret edilmemi�, en az maliyetli d���m� u de�i�kenine aktar�yoruz.
        int u = minDistance(dist, sptSet);

        // Bu d���m� (asl�nda indisini) ziyaret edildi olarak i�aretliyoruz.
        sptSet[u] = true;

        // Mevcut d���mden di�er kom�u d���mleri tarayan d�ng�m�z
        for (int v = 0; v < V; v++)

            // !sptSet[v] => E�er d���m ziyaret edilmediyse VE 
            // graph[u][v] => Graf �zerinde bu nokta bulunuyorsa VE
            // dist[u] != INT_MAX ==> Maliyet Sonsuz de�ilse VE
            // ist[u]+graph[u][v] < dist[v] => Mevcut uzakl�ktan k���kse
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])

                //Uzakl��� g�ncelliyoruz.
                dist[v] = dist[u] + graph[u][v];
    }

    // Kayna�a olan uzakl��� ekrana bast�r�yoruz.
    printSolution(dist, V);
}

// driver program to test above function
int main()
{
    /* A��rl�kl� Graf Yap�m�z�  a�a��daki gibi olu�turduk*/
    int graph[V][V] = { {0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    //0 d���m�n� ba�lang�� noktas� olarak belirttik.
    dijkstra(graph, 0);

    return 0;
}