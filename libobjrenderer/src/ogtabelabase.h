/*
# Projeto: Modelador de Banco de Dados PostgreSQL (pgModeler)
# Sub-projeto: Biblioteca libobjrenderer
# Classe: OGTabelaBase
# Descrição: Esta classe deriva a classe ObjetoGrafico e implementa um conjuto de métodos utilitáiros
#            para serem usadas pelas classes OGTabela, OGVisao e OGRelacionamento. O sufixo OG foi
#            adicionado ao nome da classe para evitar conflitos de nomes entra a classe Tabela da biblioteca
#            libpgmodeler e a classe abaixo definida.
#
# Copyright 2006-2012 - Raphael Araújo e Silva <rkhaotix@gmail.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation version 3.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# The complete text of GPLv3 is at LICENSE file on source code root directory.
# Also, you can get the complete GNU General Public License at <http://www.gnu.org/licenses/>
*/
#ifndef OG_TABELABASE_H
#define OG_TABELABASE_H

#include "objetografico.h"
#include "tabelabase.h"
#include "ogtituloobjeto.h"
#include "ogsubitemobjeto.h"

class OGTabelaBase: public ObjetoGrafico {
 private:
  Q_OBJECT

 protected:
  //Objeto gráfico poligonal que define o corpo da tabela
  QGraphicsPolygonItem *corpo;

  //Objeto descritor de título da visão
  OGTituloObjeto *titulo;

  //Sobrecarga do método ObjetoGrafico::itemChange()
  QVariant itemChange(GraphicsItemChange change, const QVariant &value);

 public:
  OGTabelaBase(TabelaBase *);
  ~OGTabelaBase(void);

 signals:
  /* Sinal emitido toda vez que a tabela é movida. Este sinal é usado
     pela classe OGRelacionamento para monitorar quando ela precisa
     atualiza a linha do relacionamento quando a tabela é movida */
  void s_objetoMovido(void);
};

#endif
