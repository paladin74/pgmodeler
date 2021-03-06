/*
# Projeto: Modelador de Banco de Dados PostgreSQL (pgModeler)
# Sub-projeto: Biblioteca libpgsqldbm_ui
# Classe: ParametroWidget
# Descrição: Definição da classe que implementa o formulário de
#            edição de parâmetro de funções.
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
#ifndef PARAMETRO_WIDGET_H
#define PARAMETRO_WIDGET_H


#include "objetobasewidget.h"
#include "ui_parametrowidget.h"
#include "tipopgsqlwidget.h"

class ParametroWidget: public ObjetoBaseWidget, public Ui::ParametroWidget {
 Q_OBJECT

 private:
   TipoPgSQLWidget *tipo_pgsql;

   //Armazena a cópia do parâmetro configurado
   Parametro parametro;

 public:
   ParametroWidget(QWidget * parent = 0);
   void definirAtributos(Parametro parametro, ModeloBD *modelo);

   /* Retorna a cópia do parâmetro configurado. Este método deve
      ser usado para se ter acesso ao parâmetro configurado */
   Parametro obterParametro(void);

 private slots:
   void hideEvent(QHideEvent *);

 public slots:
   void aplicarConfiguracao(void);
};

#endif
