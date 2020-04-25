#include "stdafx.h"
#include <stdio.h>
#include <limits.h>


// Graftaki düðüm sayýsýný V global deðiþkeni ile ifade edeceðiz.
#define V 9

//En kýsa yolu bulan yardýmcý fonksiyon.
//Ziyaret edilmemiþ düðümler içerisindeki en kýsa maliyetli düðümü return ediyor.
int minDistance(int dist[], bool sptSet[])
{
    //Ýlk baþta Sonsuz deðer atýyoruz.
    int min = INT_MAX, min_index;
    //Aþaðýdaki döngü ziyaret edilmemiþ düðümler içerisinde min deðerinden daha küçük
    //düðümleri tespit ediyor. En küçüðünü buluyor.
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    //En küçük düðümün indexini return ediyoruz.
    return min_index;
}

// Baþlangýç noktasýndan diðer düðümlere olan maliyeti yazdýran fonksiyon.
int printSolution(int dist[], int n)
{
    printf("Dugumlerin ana kaynaða olan uzakligi");
    for (int i = 0; i < V; i++)
        printf("%d tt %dn", i, dist[i]);
}

// Dijkstra algoritmasýnýn temel fonksiyonu
// Aðýrlýklý graf yapýmýzý graph[V][V] dizisinde tutuyoruz
// int src ise baþlangýç noktamýz.
void dijkstra(int graph[V][V], int src)
{
    int dist[V];     //Baþlangýç düðümünden bir baþka düðüme olan uzaklýðý burada tutacaðýz.

    bool sptSet[V];  //Düðüm ziyaret edildiðinde bu diziye aktarýyoruz. Böylece ziyaret edilmiþ düðümleri kontrol edebileceðiz.


    //Ýlk baþta Tüm düðümleri ziyaret edilmemiþ olarak iþaretliyoruz.
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    //Baþlangýç noktasýnýn maliyeti her zaman sýfýr olur.
    dist[src] = 0;

    // Tüm düðümlere olan uzaklýðýn (kaynaktan) bulunacaðý döngüye giriþ yapýyoruz.
    for (int count = 0; count < V - 1; count++)
    {
        // Henüz ziyaret edilmemiþ, en az maliyetli düðümü u deðiþkenine aktarýyoruz.
        int u = minDistance(dist, sptSet);

        // Bu düðümü (aslýnda indisini) ziyaret edildi olarak iþaretliyoruz.
        sptSet[u] = true;

        // Mevcut düðümden diðer komþu düðümleri tarayan döngümüz
        for (int v = 0; v < V; v++)

            // !sptSet[v] => Eðer düðüm ziyaret edilmediyse VE 
            // graph[u][v] => Graf üzerinde bu nokta bulunuyorsa VE
            // dist[u] != INT_MAX ==> Maliyet Sonsuz deðilse VE
            // ist[u]+graph[u][v] < dist[v] => Mevcut uzaklýktan küçükse
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])

                //Uzaklýðý güncelliyoruz.
                dist[v] = dist[u] + graph[u][v];
    }

    // Kaynaða olan uzaklýðý ekrana bastýrýyoruz.
    printSolution(dist, V);
}

// driver program to test above function
int main()
{
    /* Aðýrlýklý Graf Yapýmýzý  aþaðýdaki gibi oluþturduk*/
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

    //0 düðümünü baþlangýç noktasý olarak belirttik.
    dijkstra(graph, 0);

    return 0;
}