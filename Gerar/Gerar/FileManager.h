FILE* AbreArquivoNormal(char modo);
FILE* AbreArquivoPreferencial(char modo);
FILE* AbreArquivoCaixa(char modo);
void FechaArquivo(FILE* file);
void CadastraNormal(int senha, char canal);
void CadastraPreferencial(int senha, char canal);
void CadastraCaixa(int senha, char canal);
void ListarNormal();
void ListarPreferencial();
void ListarCaixa();
int PegarSeqNormal();
int PegarSeqPreferencial();
int PegarSeqCaixa();
void zerarDados();
