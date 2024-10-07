# Explcação do projeto java

## Classe Conta

**Classe abstract**

- Classe concreta: pode instaciar objeto diretamente
- Classe abstract: não pode instanciar o objeto diretamente

- A super é defina como defina como abastrato, ou seja, pode ter instancia de objeto diretamente, e temos métodos abstaratos (Pra ter métodos abstrato, a classe precisa ser abstrato), isso serve como modelo para as suas subclasses.

**Encapsulamento**

- Quando encapsulo algum atributo, estou ocultando, protendo o dados pra não ser acessado diretamente na subclasse, isso pra segurançae deixa o código flexivel, quando definino como **private**, para as subclasse acessar e manipular os atributos usa o método get e set, get pegar o o atrbuto, ele vai retornar, e método set, o atrbuto passa por parâmettro no meu método, isso é deixa certo padrão para subclasses acessarem o atrbuto da superclasse. Outra forma da subclasse acessar, o atributo é defina como protected, quando definido como protected, o atrbuto é acessivel pelo super e subclasse.

**Métodos concretos e métodos abstract**

- Método concreto: tem a implementção da lógica do método

```java
public class Conta {
    public void transeferir(Conta outraConta,double Valor) {
        if(this.sacar(Valor)) {
            outraConta.depositar(Valor);
        }
    }
}
```

- Método abstrato: não tem a implementação da lógica do método, só tem a assinatura

```java
public class Conta {
    public abstract void depositar(double Valor);
}
```

- Quando tem método abstrato, as subclasses tem que sobrescrever o método, sendo método age de maneira diferenete em cada subclasse

**Polimorfismo**

- Poliformismo é varías formas, de se fazer o código, tem reutização de código, e deixar ele mais flexível.

- O método abstract, é um exemplo disso, quando tem só assinatura do meu método, as subclaase vão sobrescever o método abstarct, assim o método tem comportamento especifica desse código, ele não está criando, está reutizando o código.

- E para sobrever o método, o método tem que ter o mesmo nome e tipo de retorno.

**Construtor**

- O construtor é um método especial, cujo nome tem que ser o mesmo da própria classe

- Construtor default: não tem parametro, num classe onde so tem atrbutos e métodos, tem construtor, só que é default.

- Construtor não default: tem parâmetro, isso, facilita dna hora de instanciar objeto usando o construtor não default, posso atribuir valor ao meu atrbuto na hora que instancio a classe, por os atrbutos passa por parâmetro, isso otimiza linha de código.

## Classe Conta_corrente

- Ela é uma subclasse da conta Conta, usando a palavara **extends**.

**Herança**

- QUando a subclasse herda **atributos** e **métodos** da super classe, isso evita duplicidade de código, tendo reutilização no meu código.







