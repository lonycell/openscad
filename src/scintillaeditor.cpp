#include <iostream>
#include <QString>
#include <QChar>
#include <Qsci/qscilexercpp.h>
#include "scintillaeditor.h"

ScintillaEditor::ScintillaEditor(QWidget *parent) : EditorInterface(parent)
{
	scintillaLayout = new QVBoxLayout(this);
	qsci = new QsciScintilla(this);
	scintillaLayout->addWidget(qsci);
	qsci->setBraceMatching (QsciScintilla::SloppyBraceMatch);
	qsci->setWrapMode(QsciScintilla::WrapWord);
	initFont();
        initMargin();
        initLexer();


}
void ScintillaEditor::indentSelection()
{

}
void ScintillaEditor::unindentSelection()
{
	 
}
void ScintillaEditor::commentSelection() 
{

}
void ScintillaEditor::uncommentSelection()
{
	
}
void ScintillaEditor::setPlainText(const QString &text)
{
	qsci->setText(text); 
}
QString ScintillaEditor::toPlainText()
{
	return qsci->text();
}
void ScintillaEditor::highlightError(int error_pos) 
{

}
void ScintillaEditor::unhighlightLastError() 
{

}
void ScintillaEditor::setHighlightScheme(const QString &name)
{

}
void ScintillaEditor::insertPlainText(const QString &text)
{
	qsci->setText(text); 
}

void ScintillaEditor::undo()
{
	qsci->undo(); 
}

void ScintillaEditor::redo()
{
	qsci->redo(); 
}

void ScintillaEditor::cut()
{
	qsci->cut();
}

void ScintillaEditor::copy()
{
	qsci->copy(); 
}

void ScintillaEditor::paste()
{ 
	qsci->paste();
}

void ScintillaEditor::zoomIn()
{
	qsci->zoomIn(); 
}

void ScintillaEditor::zoomOut() 
{
	qsci->zoomOut(); 
}


void ScintillaEditor::initFont()
{
    QFont font("Courier", 12);
    font.setFixedPitch(true);
    qsci->setFont(font);

}

void ScintillaEditor::initMargin()
{
    QFontMetrics fontmetrics = QFontMetrics(qsci->font());
    qsci->setMarginsFont(qsci->font());
    qsci->setMarginWidth(0, fontmetrics.width(QString::number(qsci->lines())) + 6);
    qsci->setMarginLineNumbers(0, true);
    qsci->setMarginsBackgroundColor(QColor("#cccccc"));
 
    connect(qsci, SIGNAL(textChanged()), this, SLOT(onTextChanged()));
}

void ScintillaEditor::onTextChanged()
{
    QFontMetrics fontmetrics = qsci->fontMetrics();
    qsci->setMarginWidth(0, fontmetrics.width(QString::number(qsci->lines())) + 6);
}

void ScintillaEditor::initLexer()
{
    QsciLexerCPP *lexer = new QsciLexerCPP();
    lexer->setDefaultFont(qsci->font());
    lexer->setFoldComments(true);
    qsci->setLexer(lexer);
}