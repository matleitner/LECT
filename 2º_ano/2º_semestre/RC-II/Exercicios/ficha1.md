## 1.

## a) F, R1 foi configurado com uma prioridade maior 
## b) V
## c) F, não porque a rede 192.3.3.0 não é anúnciada no processo de RIP
## d) F, O custo é 1 em vez de 2 porque faz um único salto até chegar a 192.0.46.0/24
## e) V
## f) V, anuncia o caminho por R6, ( -(1 metric)  f1/0 R5 -(1metric) R6 - custo total = 2)
## g) F, porque pode ser o caminho que aprendeu por cima f0/0 - R1-R2-R4→ 192.0.46.0/24, custo 3 
## h) F, excede as 5 redes ele no RIP response, ele anuncia: todas as redes exceto 192.0.12.0 192.13.0 pq aprendeu via f0/0 (split horizon), e n anuncia 192.3.3.0 192.2.2.0 porque não estão incluidas na configuração.

## i) V
## j) F, muda, retira a possibilidade de caminho R1→R3→R4 ficando só R1→R2→R4

# 2.

## a) F, o custo é 3 não 4
## b) F, tem apenas o melhor caminho

## c) F, Sw2 e Sw3 não estão incluidos na configuração OSPF
## d) F, via tem de ser Local
## e) V, cada Router Link State tem um Id unico 6 routers 6 router link states entries
## f) F, cada router tem 1 entrada Net Link State, 3 routers têm OSPFv3, mas apenas 2 redes são de transito logo 2 Net Link State entries

## g) V, o LSA do roteador R3 indica que o Designated Router é o R5


## h) V, O mesmo LSA indica que na rede 192.0.13.0, o DR é 192.0.13.1 (R1). O ID de um Net LSA é o endereço IP do DR

## i) F, independementemente do números de saltos até lá chegar a métrica é a distância de saída do R5 

## j) V, independentente do caminho o custo é 4

## k) V 

