#include <iostream>
#define MAX 10

using namespace std;

struct produto
{
    int numeroproduto;
    string nomeproduto;
    string nomeprodutolist;
    float precoproduto;
    int estoqueproduto;
};

int main()
{
    string mododeini;
    int opcaocompra;
    bool opcaocompravrf;
    int valort;
    float valorinserido;
    float troco;
    float maisdinheiro;
    char verificador;
    int contadorcls = 0;
    float faturamentototal = 0;
    float podefaturar = 0;

// Declara��o dos produtos, pre�os e quantidade em estoque.
    struct produto produtos[5];

    for(int i = 0; i < 5; i++)
    {
        produtos[i].numeroproduto = i;
        produtos[i].estoqueproduto = 0;
    }

    produtos[0].nomeproduto = "Doritos-----";
    produtos[1].nomeproduto = "Coca-Cola---";
    produtos[2].nomeproduto = "Snickers----";
    produtos[3].nomeproduto = "Agua--------";
    produtos[4].nomeproduto = "Agua com gas";

    produtos[0].nomeprodutolist = "Doritos";
    produtos[1].nomeprodutolist = "Coca-Cola";
    produtos[2].nomeprodutolist = "Snickers";
    produtos[3].nomeprodutolist = "Agua";
    produtos[4].nomeprodutolist = "Agua com gas";

    produtos[0].precoproduto = 6.00;
    produtos[1].precoproduto = 5.00;
    produtos[2].precoproduto = 4.00;
    produtos[3].precoproduto = 2.00;
    produtos[4].precoproduto = 3.00;

//Modo de inicializa��o (Usu�rio ou Administrador)
    do
    {
        system("clear||cls");
        cout << "Insira o modo que deseja inicializar:\n1 - Usuario\n2 - Administrador\n3 - Finalizar programa" << endl;

        //Modo de inicializa��o com op��o inv�lida
        do
        {
            cin >> mododeini;
            if(mododeini != "1" && mododeini != "2" && mododeini != "3")
            {
                cout << "Opcao invalida, insira novamente! :" << endl;
            }
        }
        while(mododeini != "1" && mododeini != "2" && mododeini != "3");

        //Modo de inicializa��o 3 - Encerra o programa
        if(mododeini == "3")
        {
            cout << "Programa finalizado!" << endl;
            return 0;
        }
//MODO USU�RIO
        if(mododeini == "1")
        {
//Sele��o de produtos
            do
            {
                cout << "MODO USUARIO" << endl;
                cout << "Selecione a opcao desejada:  " << endl;
                for(int i = 0; i < 5; i++)
                {
                    cout << i << " - " << produtos[i].nomeproduto << "   " << "Preco: R$" << produtos[i].precoproduto << "   Quantidade em estoque: " << produtos[i].estoqueproduto << endl;
                }
                cout << "\n5 - Finalizar Programa\n6 - Voltar para a inicializacao" << endl;
                troco = 0;

                opcaocompra = 0;
                cin >> opcaocompra;
                opcaocompravrf = true;
//ETAPA DE VENDA
//Se a opcao inserida for maior que 0 ou menor ou igual a 4 pede para o usu�rio digitar o valor inserido
                if(opcaocompra >= 0 && opcaocompra <= 4 && produtos[opcaocompra].estoqueproduto > 0)
                {
                    valort += produtos[opcaocompra].precoproduto;
                    produtos[opcaocompra].estoqueproduto--;
                    cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\nProduto selecionado: " << produtos[opcaocompra].nomeprodutolist << " - Total: R$" << produtos[opcaocompra].precoproduto << endl;
                    cout << "Insira o dinheiro e digite o valor inserido: " << endl;
                    valorinserido = 0;
                    cin >> valorinserido;

                    system("clear||cls");

                    //Enquanto o valor do dinheiro for insuficiente, solicita a entrada de mais dinheiro
                    do
                    {
                        if(valorinserido < produtos[opcaocompra].precoproduto)
                        {
                            cout << "Valor insuficiente, insira mais dinheiro!" << endl;
                            cin >> maisdinheiro;
                            valorinserido += maisdinheiro;
                        }
                    }
                    while(valorinserido < produtos[opcaocompra].precoproduto);

                    if((valorinserido - produtos[opcaocompra].precoproduto) > 0)
                    {
                        troco = valorinserido - produtos[opcaocompra].precoproduto;
                        valorinserido = produtos[opcaocompra].precoproduto;
                    }

                    if(valorinserido == produtos[opcaocompra].precoproduto)
                    {
                        faturamentototal += produtos[opcaocompra].precoproduto;
                        cout << "\nLiberando seu produto (" << produtos[opcaocompra].nomeprodutolist << ") e o seu troco de R$" << troco << "." << endl;
                        cout << "\nObrigado pela preferencia!" << endl;
                        cout << "Deseja comprar mais algum produto? (s/n)" << endl;
                        cin >> verificador;
                        if(verificador == 's')
                        {
                            opcaocompravrf = false;
                        }
                    }
                }
//FALTA NO ESTOQUE
                else if(opcaocompra >= 0 && opcaocompra <= 4 && produtos[opcaocompra].estoqueproduto <= 0)
                {
                    cout << "PRODUTO INDISPONIVEL!!! SELECIONE NOVAMENTE: " << endl;
                    opcaocompravrf = false;
                }

                if(opcaocompra == 5)
                {
                    cout << "Programa finalizado!" << endl;
                    return 0;
                }

                if(opcaocompra == 6)
                {
                    opcaocompravrf = true;
                    mododeini = 1;
                }


            }
            while(opcaocompravrf == false);
        }
//MODO ADMINISTRADOR
        if(mododeini == "2")
        {
            do
            {
                do
                {
                    system("clear||cls");
                    cout << "MODO ADMINISTRADOR\n\n" << endl;
                    for(int i = 0; i < 5; i++)
                    {
                        cout << produtos[i].nomeproduto << " - Quantidade restante no estoque: " << produtos[i].estoqueproduto << endl;
                    }
                    podefaturar = 0;
                    for(int i = 0; i < 5; i++)
                    {
                        podefaturar = podefaturar + (produtos[i].estoqueproduto * produtos[i].precoproduto);
                    }

                    cout << "\n\nQuantia faturada ate o momento: R$" << faturamentototal << endl;
                    cout << "Quantia que pode ser faturada com o estoque atual: R$" << podefaturar << endl;
                    cout << "\n1 - Repor completamente o estoque (5 itens de cada)" << endl;
                    cout << "2 - Finalizar Programa" << endl;
                    cout << "3 - Voltar para a inicializacao" << endl;

                    opcaocompra = 0;
                    cin >> opcaocompra;
                    if(opcaocompra == 1)
                    {
                        for(int i = 0; i < 5; i++)
                        {
                            produtos[i].estoqueproduto = 5;
                        }

                    }
                    if(opcaocompra == 2)
                    {
                        cout << "Programa finalizado!" << endl;
                        return 0;
                    }
                    if(opcaocompra == 3)
                    {
                        mododeini = "1";
                        opcaocompravrf = true;
                    }
                }
                while(opcaocompra == 1);

            }
            while(opcaocompravrf == false);
        }

    }
    while(mododeini != "2");

    return 0;
}
