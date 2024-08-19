{
    TF1 *neff = new TF1("neff", "x>[0]?[1]:0", 0, 1000);
    neff->SetParameter(0, 1);
    neff->SetParameter(1, -1);
    KPad det(50, 300);
    det.Neff = neff;
    det.Voltage = 70;
    det.SetUpVolume(1);
    det.SetUpElectrodes();

  

    TCanvas c1;
    det.SetEntryPoint(25, 10, 0.5);
    det.SetExitPoint(20, 20, 0.5);
    det.Temperature = 300;
    det.diff = 1;
    det.ShowMipIR(80);

    TCanvas c2;
    det.MipIR(200);
    det.sum->DrawCopy();
    det.pos->Draw("SAME");
    det.neg->Draw("SAME");

    TCanvas c3;
    KElec tct;
    tct.RCshape(40e-12,50,10000,det.sum);
    det.sum->Draw("HIST");

}
