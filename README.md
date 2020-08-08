<h1> Projeto do jogo de cartas Uno feito em C e C++ </h1>

<p> Trabalho feito para a matéria de Estrutura de Dados, usando pilha, fila e lista simplesmente encadeada | Nota final = 9.7 </p>
<h3> Projeto contem erros na parte da jogabilidade, já que em ambiente cmd é mais complexo, Porém se seguir as regras o jogo funcionara normalmente.</h3>

![Screenshot](https://i.postimg.cc/X7pcdfL5/2020-08-07-22-37.png)

<h3> Como Funciona </h3>

![Screenshot](https://i.postimg.cc/1RWr8CGP/2020-08-07-22-35-02.png)

<p>Em baralho.h se inicia uma pilha contendo as cartas. Cada carta tem um número e uma cor. De maneira aleatória essas cartas são inseridas na tp_pilha baralho onde depois será usada em mao.h que é lista simplesmente encadeada.
De forma aleatória as cartas da pilha são inseridas na mão dos jogadores e por último é colocada na mesa.
Depois começa o jogo de fato. </p>

<h3> Como Jogar </h3>

![Screenshot](https://i.postimg.cc/rsY17sVz/2020-08-07-22-35-01.png)

<p> Começando com o Jogador 1 ele escolhe sua carta baseada na mesa.
Se for igual à cor ou o número, essa carta passa por uma verificação para ver se essa carta realmente exite na mão do jogador.
Se existir a jogada é validada e a carta jogada vai para a pilha da Mesa, fazendo assim com que o jogador 2 jogue. 
Toda rodada um verificador é passado para saber se algum jogador tenha 0 cartas.
E elas são divididas em Cores que vão de 0 a 4 (representando uma cor Blue, Green, Red, Yellow e Black) e os Números que vão de 0 a 9 tendo as cartas especiais +2 | +4 | Bloqueio | Reverter | Trocar de Cor. 
Todas as cartas funcionam como se fosse um Uno normal, sendo o +2 adicionando mais duas cartas ao próximo ou Bloqueando a sua rodada</p>

<h3> Como as cartas são salvas </h3>

![Screenshot](https://i.postimg.cc/nL866crd/2020-08-07-23-12.png)
