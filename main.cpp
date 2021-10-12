#include <QCoreApplication>
QVector<double> forward_stroke(QVector<double> &before, int &cop);
QVector<double> revers_stroke(QVector<double> &after);
QVector<double> conv_ion(QVector<double> &after, QVector<double> &before);
int main()
{
    int cop = 0;
    QVector <double> before;
    QVector <double> after;
    before << 12 << 1 << 154 << 113 << 10;
    ///Прямой ход
    after = forward_stroke(before, cop);
    qDebug() << after << Qt::endl << cop;
    ///Обратный ход
    before.clear();
    before= revers_stroke(after);
    qDebug() << before;
    ///Свёрстка
    QVector <double> convolution;
    convolution= conv_ion(after, before);
    qDebug() << convolution;

    return 0;
}
QVector<double> forward_stroke(QVector<double> &before, int &cop){
    int re,im;
    QVector <double> after;
    for(int i = 0; i < before.size(); i++){
        re = im = 0;
        for(int k = 0; k < before.size(); k++){
            re += before[k] * qCos((M_PI*2*i*k)/before.size());
            im += before[k] * qSin((M_PI*2*i*k)/before.size());
            cop += 2;
        }
        cop += 3;
        after.push_back((re + im)/* / (double)mas.size()*/);
    }
    return after;
}
QVector<double> revers_stroke(QVector<double> &after){
    QVector <double> before;
    int re,im;
    for(int i = 0; i < after.size(); i++){
        re = im = 0;
        for(int k = 0; k < after.size(); k++){
            re += after[k] * qCos((M_PI*2*i*k)/after.size());
            im += after[k] * qSin((M_PI*2*i*k)/after.size());
        }
        before.push_back((re + im) / (double)after.size());
    }
    return before;
}
QVector<double> conv_ion(QVector<double> &after, QVector<double> &before){
    QVector <double> convolution;
    convolution.fill(0, after.size() * 2);
    qDebug() << convolution;
    for(int i = 0; i < before.size(); i++){
        for(int j = 0; j < after.size(); j++){
            convolution[i + j] += after[j] * before[i];
        }
    }
    return convolution;
}
