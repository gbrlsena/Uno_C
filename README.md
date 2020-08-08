<h1> Projeto do jogo de cartas Uno feito em C e C++ </h1>

<p> Trabalho feito para a matéria de Estrutura de Dados, usando pilha, fila e lista simplesmente encadeada | <b> Nota final = 9.7  </b> </p>
<h3> Projeto contem erros na parte da jogabilidade, já que em ambiente cmd é mais complexo, Porém se seguir as regras o jogo funcionara normalmente.</h3>

![Screenshot](https://i.postimg.cc/0NZ7f8yB/2020-08-07-22-37.png)

<h3> Como Funciona </h3>

![Screenshot](https://i.postimg.cc/t4jrv49q/2020-08-07-22-35-02.png)

<p>Em baralho.h se inicia uma pilha contendo as cartas. Cada carta tem um número e uma cor. De maneira aleatória essas cartas são inseridas na tp_pilha baralho onde depois será usada em mao.h que é lista simplesmente encadeada.
De forma aleatória as cartas da pilha são inseridas na mão dos jogadores e por último é colocada na mesa.
Depois começa o jogo de fato. </p>

<p> Começando com o Jogador 1 ele escolhe sua carta baseada na mesa.
Se for igual à cor ou o número, essa carta passa por uma verificação para ver se essa carta realmente exite na mão do jogador.
Se existir a jogada é validada e a carta jogada vai para a pilha da Mesa, fazendo assim com que o jogador 2 jogue. 
Toda rodada um verificador é passado para saber se algum jogador tenha 0 cartas.
E elas são divididas em Cores que vão de 0 a 4 (representando uma cor Blue, Green, Red, Yellow e Black) e os Números que vão de 0 a 9 tendo as cartas especiais +2 | +4 | Bloqueio | Reverter | Trocar de Cor. 
Todas as cartas funcionam como se fosse um Uno normal, sendo o +2 adicionando mais duas cartas ao próximo ou bloqueio bloqueando a sua rodada do proximo</p>

<h3> Como Jogar </h3>

![Screenshot](https://i.postimg.cc/Kvdfkv17/2020-08-07-22-35-01.png)

<p> Olhando como exemplo a foto, a carta da mesa é Cor = 0 e Número = Block 
  O jogador 1 só pode jogar as cartas digitando da seguinte forma <b> 0 Block - 0 9 - 07 - 0 2 </b>
  /p>

<h3> Como as cartas são salvas </h3>

![Screenshot](https://i.postimg.cc/nL866crd/2020-08-07-23-12.png)
