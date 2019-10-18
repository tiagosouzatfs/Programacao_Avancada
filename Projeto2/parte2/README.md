ESCULTOR DIGITAL - PARTE 2

Esta parte do trabalho tem por finalidade dar um upgrade na versão anterior
do escultor digital. Este projeto utiliza os conhecimentos passados em sala
sobre classes abstratas para manipulação das figuras geométricas, realizando 
operações de desenho em uma matriz. Foram utilizados os conceitos de herança
criando uma classe herdeira da classe sculptor chamada figura geométrica.
Nela foi criada uma função virtual pura draw(Sculptor &t) que instrua o objeto
a se desenhar em um objeto do tipo Sculptor. E Esta função foi implementada 
nas subclasses concretas da classe FiguraGeometrica. Foram criadas as seguintes
subclasses concretas: putbox, cutbox, putvoxel, cutvoxel, putsphere, cutsphere,
putellipsoid e cutellipsoid. Foi utilizado recursos para ler figuras gravadas 
em um arquivo e desenhá-las conforme as instruções presentes no arquivo. Por 
fim, foi criado um programa exemplo para testar as implementações.Toda a figura 
foi armazenada em um array de ponteiros para FiguraGeometrica, e para isso 
foram utilizadas as classes vector, string e stringstream, bem como seus 
respetivos iterators para realizar a implementação das funcionalidades, e ainda,
representar em um arquivo usando classes para converter a figura em uma 
escultura digital no formato OFF.
