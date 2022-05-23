#include <stdio.h>
#define INFINITY 9999
#define MAX 10


void Dijkstra(int Graph[MAX][MAX], int n, int start) {
  int cost[MAX][MAX], distance[MAX], pred[MAX];           // deklaracja zmiennych
  int visited[MAX], count, mindistance, nextnode, i, j;

  // tworzenie tablicy
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)

      if (Graph[i][j] == 0)
        cost[i][j] = INFINITY; // jezeli wartość komórki Graph o współrzędnych [i,j] jest równa 0 to ustawiamy wartości na komórce cost o współrzędnych [i,j] na nieskończoność

      else
        cost[i][j] = Graph[i][j]; // w przeciwnym wypadku wartość komórki Graph o współrzędnych [i,j] będzie taka jak w cost

  for (i = 0; i < n; i++) { // przechodzimy pętlą przez wierzechołki i ustawiamy dystans jako wagę wierzchołka startowego
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) { // pętla przechodząca, jeśli zostały jeszcze jakieś wierzchołki
    mindistance = INFINITY; // ustawiamy wartość zmiennej "mindistance" na nieskończoność


    for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i]) { // przechodzimy po wszystkich wierzchołkach i jeśli wartość dystansu jest mniejszy niż wartośc w naszej dotychdczasowej zmiennej to wstawiamy tą wartość pod zmienną
        mindistance = distance[i];
        nextnode = i;
      }

    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i]) // sprawdzenie czy odwiedziliśmy już odpowiedni wierzchołek
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i]; // ustawienie nowego dystansu, jeśli minimalny dystans plus waga kolejnego węzła jest mniesza od dystansu
          pred[i] = nextnode;
        }
    count++;
  }

  //wypisanie dystansu
  for (i = 0; i < n; i++)

  if (i != start) {
      printf("\nDistance from source to %d: %d", i, distance[i]);
    }

}
int main() {
  int Graph[MAX][MAX], i, j, n, u;
  n = 5;
// ustawienie macierzy
  Graph[0][0] = 0;
  Graph[0][1] = 3;
  Graph[0][2] = 7;
  Graph[0][3] = 1;
  Graph[0][4] = 2;

  Graph[1][0] = 3;
  Graph[1][1] = 0;
  Graph[1][2] = 5;
  Graph[1][3] = 2;
  Graph[1][4] = 2;

  Graph[2][0] = 7;
  Graph[2][1] = 5;
  Graph[2][2] = 0;
  Graph[2][3] = 6;
  Graph[2][4] = 5;

  Graph[3][0] = 1;
  Graph[3][1] = 2;
  Graph[3][2] = 6;
  Graph[3][3] = 0;
  Graph[3][4] = 1;

  Graph[4][0] = 2;
  Graph[4][1] = 2;
  Graph[4][2] = 5;
  Graph[4][3] = 1;
  Graph[4][4] = 2;

  u = 0;
  Dijkstra(Graph, n, u);

  return 0;
}
