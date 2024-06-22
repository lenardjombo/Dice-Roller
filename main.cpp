#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QRandomGenerator>

class DiceRoller : public QWidget {
    Q_OBJECT

public:
    DiceRoller(QWidget *parent = nullptr);

private slots:
    void rollDice();

private:
    QLabel *resultLabel;
    QPushButton *rollButton;
};

DiceRoller::DiceRoller(QWidget *parent) : QWidget(parent) {
    resultLabel = new QLabel("Roll the dice!", this);
    resultLabel->setAlignment(Qt::AlignCenter);

    rollButton = new QPushButton("Roll", this);
    connect(rollButton, &QPushButton::clicked, this, &DiceRoller::rollDice);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(resultLabel);
    layout->addWidget(rollButton);
    setLayout(layout);

    setWindowTitle("Dice Roller");
    resize(200, 110);
}

void DiceRoller::rollDice() {
    int result = QRandomGenerator::global()->bounded(1, 7); // Generates a random number between 1 and 6
    resultLabel->setText("You rolled:  " + QString::number(result));
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    DiceRoller diceRoller;
    diceRoller.show();
    return app.exec();
}

#include "main.moc"
