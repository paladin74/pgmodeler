/*
# Projeto: Modelador de Banco de Dados PostgreSQL (pgModeler)
# Sub-projeto: Biblioteca libpgsqldbm_ui
# Classe: FormConfiguracao
# Descrição: Formulario que reúne todos os widgets de configuração.
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
#ifndef FORM_CONFIGURACAO_H
#define FORM_CONFIGURACAO_H

#include "ui_formconfiguracao.h"
#include "confaparenciawidget.h"
#include "confgeralwidget.h"
#include "confconexoeswidget.h"

class FormConfiguracao: public QDialog, public Ui::FormConfiguracao {
 private:
  Q_OBJECT

  ConfGeralWidget *conf_geral;
  ConfAparenciaWidget *conf_aparencia;
  ConfConexoesWidget *conf_conexoes;

 public:
  static const int WGT_CONF_GERAL=0,
                   WGT_CONF_APARENCIA=1,
                   WGT_CONF_CONEXOES=2;
  FormConfiguracao(QWidget * parent = 0, Qt::WindowFlags f = 0);
  ConfBaseWidget *obterWidgetConfiguracao(unsigned idx);

 public slots:
  void aplicarConfiguracao(void);
  void carregarConfiguracao(void);
  void close(void);

 private slots:
  void restaurarPadroes(void);
};

#endif
