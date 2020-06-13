namespace win_iap_ymodem
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.btn_Port = new System.Windows.Forms.Button();
            this.lbl_Port = new System.Windows.Forms.Label();
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.lbl_Bps = new System.Windows.Forms.Label();
            this.cbx_Port = new System.Windows.Forms.ComboBox();
            this.cbx_Baud = new System.Windows.Forms.ComboBox();
            this.txb_FilePath = new System.Windows.Forms.TextBox();
            this.btn_SelectFile = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btn_Clear = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.tbx_show = new System.Windows.Forms.TextBox();
            this.btn_Erase = new System.Windows.Forms.Button();
            this.btn_Upload = new System.Windows.Forms.Button();
            this.btn_RunApp = new System.Windows.Forms.Button();
            this.btn_Config = new System.Windows.Forms.Button();
            this.btn_Update = new System.Windows.Forms.Button();
            this.btn_IAPMenu = new System.Windows.Forms.Button();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.cbx_PageSize = new System.Windows.Forms.ComboBox();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // btn_Port
            // 
            this.btn_Port.Location = new System.Drawing.Point(92, 93);
            this.btn_Port.Name = "btn_Port";
            this.btn_Port.Size = new System.Drawing.Size(70, 30);
            this.btn_Port.TabIndex = 0;
            this.btn_Port.Text = "打开串口";
            this.btn_Port.UseVisualStyleBackColor = true;
            this.btn_Port.Click += new System.EventHandler(this.btn_Port_Click);
            // 
            // lbl_Port
            // 
            this.lbl_Port.AutoSize = true;
            this.lbl_Port.Location = new System.Drawing.Point(6, 27);
            this.lbl_Port.Name = "lbl_Port";
            this.lbl_Port.Size = new System.Drawing.Size(53, 12);
            this.lbl_Port.TabIndex = 1;
            this.lbl_Port.Text = "串口号：";
            // 
            // progressBar1
            // 
            this.progressBar1.BackColor = System.Drawing.SystemColors.ControlLight;
            this.progressBar1.Location = new System.Drawing.Point(251, 363);
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(471, 22);
            this.progressBar1.TabIndex = 2;
            // 
            // serialPort1
            // 
            this.serialPort1.BaudRate = 115200;
            this.serialPort1.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.serialPort1_DataReceived);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.Filter = "bin文件(*.bin)|*.bin|hex文件(*.hex)|*.hex";
            this.openFileDialog1.FileOk += new System.ComponentModel.CancelEventHandler(this.openFileDialog1_FileOk);
            // 
            // lbl_Bps
            // 
            this.lbl_Bps.AutoSize = true;
            this.lbl_Bps.Location = new System.Drawing.Point(6, 61);
            this.lbl_Bps.Name = "lbl_Bps";
            this.lbl_Bps.Size = new System.Drawing.Size(53, 12);
            this.lbl_Bps.TabIndex = 3;
            this.lbl_Bps.Text = "波特率：";
            // 
            // cbx_Port
            // 
            this.cbx_Port.FormattingEnabled = true;
            this.cbx_Port.Location = new System.Drawing.Point(65, 24);
            this.cbx_Port.Name = "cbx_Port";
            this.cbx_Port.Size = new System.Drawing.Size(98, 20);
            this.cbx_Port.TabIndex = 5;
            this.cbx_Port.DropDown += new System.EventHandler(this.cbx_Port_DropDown);
            // 
            // cbx_Baud
            // 
            this.cbx_Baud.FormattingEnabled = true;
            this.cbx_Baud.Items.AddRange(new object[] {
            "Custom",
            "1200",
            "2400",
            "4800",
            "9600",
            "14400",
            "19200",
            "38400",
            "56000",
            "57600",
            "115200",
            "130000",
            "256000"});
            this.cbx_Baud.Location = new System.Drawing.Point(65, 58);
            this.cbx_Baud.Name = "cbx_Baud";
            this.cbx_Baud.Size = new System.Drawing.Size(98, 20);
            this.cbx_Baud.TabIndex = 6;
            // 
            // txb_FilePath
            // 
            this.txb_FilePath.BackColor = System.Drawing.SystemColors.Window;
            this.txb_FilePath.Location = new System.Drawing.Point(251, 336);
            this.txb_FilePath.Name = "txb_FilePath";
            this.txb_FilePath.Size = new System.Drawing.Size(471, 21);
            this.txb_FilePath.TabIndex = 7;
            // 
            // btn_SelectFile
            // 
            this.btn_SelectFile.Location = new System.Drawing.Point(183, 335);
            this.btn_SelectFile.Name = "btn_SelectFile";
            this.btn_SelectFile.Size = new System.Drawing.Size(64, 23);
            this.btn_SelectFile.TabIndex = 8;
            this.btn_SelectFile.Text = "选择文件";
            this.btn_SelectFile.UseVisualStyleBackColor = true;
            this.btn_SelectFile.Click += new System.EventHandler(this.btn_SelectFile_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.btn_Clear);
            this.groupBox1.Controls.Add(this.btn_Port);
            this.groupBox1.Controls.Add(this.lbl_Bps);
            this.groupBox1.Controls.Add(this.lbl_Port);
            this.groupBox1.Controls.Add(this.cbx_Port);
            this.groupBox1.Controls.Add(this.cbx_Baud);
            this.groupBox1.Location = new System.Drawing.Point(4, 2);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(174, 133);
            this.groupBox1.TabIndex = 10;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "端口操作";
            this.groupBox1.Enter += new System.EventHandler(this.groupBox1_Enter);
            // 
            // btn_Clear
            // 
            this.btn_Clear.Location = new System.Drawing.Point(12, 93);
            this.btn_Clear.Name = "btn_Clear";
            this.btn_Clear.Size = new System.Drawing.Size(70, 30);
            this.btn_Clear.TabIndex = 16;
            this.btn_Clear.Text = "清除窗口";
            this.btn_Clear.UseVisualStyleBackColor = true;
            this.btn_Clear.Click += new System.EventHandler(this.btn_Clear_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.tbx_show);
            this.groupBox2.Location = new System.Drawing.Point(184, 2);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(538, 330);
            this.groupBox2.TabIndex = 11;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "串口数据";
            // 
            // tbx_show
            // 
            this.tbx_show.BackColor = System.Drawing.SystemColors.HighlightText;
            this.tbx_show.Location = new System.Drawing.Point(6, 18);
            this.tbx_show.Multiline = true;
            this.tbx_show.Name = "tbx_show";
            this.tbx_show.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.tbx_show.Size = new System.Drawing.Size(526, 302);
            this.tbx_show.TabIndex = 9;
            this.tbx_show.TextChanged += new System.EventHandler(this.tbx_show_TextChanged);
            this.tbx_show.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.tbx_show_KeyPress);
            // 
            // btn_Erase
            // 
            this.btn_Erase.Location = new System.Drawing.Point(92, 54);
            this.btn_Erase.Name = "btn_Erase";
            this.btn_Erase.Size = new System.Drawing.Size(70, 30);
            this.btn_Erase.TabIndex = 12;
            this.btn_Erase.Text = "擦除固件";
            this.btn_Erase.UseVisualStyleBackColor = true;
            this.btn_Erase.Click += new System.EventHandler(this.btn_Erase_Click);
            // 
            // btn_Upload
            // 
            this.btn_Upload.Location = new System.Drawing.Point(12, 20);
            this.btn_Upload.Name = "btn_Upload";
            this.btn_Upload.Size = new System.Drawing.Size(70, 30);
            this.btn_Upload.TabIndex = 13;
            this.btn_Upload.Text = "读取固件";
            this.btn_Upload.UseVisualStyleBackColor = true;
            this.btn_Upload.Click += new System.EventHandler(this.btn_Upload_Click);
            // 
            // btn_RunApp
            // 
            this.btn_RunApp.Location = new System.Drawing.Point(12, 54);
            this.btn_RunApp.Name = "btn_RunApp";
            this.btn_RunApp.Size = new System.Drawing.Size(70, 30);
            this.btn_RunApp.TabIndex = 14;
            this.btn_RunApp.Text = "重启设备";
            this.btn_RunApp.UseVisualStyleBackColor = true;
            this.btn_RunApp.Click += new System.EventHandler(this.btn_RunApp_Click);
            // 
            // btn_Config
            // 
            this.btn_Config.Location = new System.Drawing.Point(92, 88);
            this.btn_Config.Name = "btn_Config";
            this.btn_Config.Size = new System.Drawing.Size(70, 30);
            this.btn_Config.TabIndex = 18;
            this.btn_Config.Text = "配置参数";
            this.btn_Config.UseVisualStyleBackColor = true;
            this.btn_Config.Click += new System.EventHandler(this.btn_Config_Click);
            // 
            // btn_Update
            // 
            this.btn_Update.BackColor = System.Drawing.SystemColors.ControlLight;
            this.btn_Update.ForeColor = System.Drawing.SystemColors.Desktop;
            this.btn_Update.Location = new System.Drawing.Point(92, 20);
            this.btn_Update.Name = "btn_Update";
            this.btn_Update.Size = new System.Drawing.Size(70, 30);
            this.btn_Update.TabIndex = 15;
            this.btn_Update.Text = "更新固件";
            this.btn_Update.UseVisualStyleBackColor = false;
            this.btn_Update.Click += new System.EventHandler(this.btn_Update_Click);
            // 
            // btn_IAPMenu
            // 
            this.btn_IAPMenu.BackColor = System.Drawing.SystemColors.ControlLight;
            this.btn_IAPMenu.ForeColor = System.Drawing.SystemColors.Desktop;
            this.btn_IAPMenu.Location = new System.Drawing.Point(12, 88);
            this.btn_IAPMenu.Name = "btn_IAPMenu";
            this.btn_IAPMenu.Size = new System.Drawing.Size(70, 30);
            this.btn_IAPMenu.TabIndex = 16;
            this.btn_IAPMenu.Text = "读取配置";
            this.btn_IAPMenu.UseVisualStyleBackColor = true;
            this.btn_IAPMenu.Click += new System.EventHandler(this.btn_IAPMenu_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.btn_Update);
            this.groupBox3.Controls.Add(this.btn_RunApp);
            this.groupBox3.Controls.Add(this.btn_IAPMenu);
            this.groupBox3.Controls.Add(this.btn_Upload);
            this.groupBox3.Controls.Add(this.btn_Config);
            this.groupBox3.Controls.Add(this.btn_Erase);
            this.groupBox3.Location = new System.Drawing.Point(4, 141);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(174, 244);
            this.groupBox3.TabIndex = 17;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "数据操作";
            this.groupBox3.Enter += new System.EventHandler(this.groupBox3_Enter);
            // 
            // cbx_PageSize
            // 
            this.cbx_PageSize.FormattingEnabled = true;
            this.cbx_PageSize.Items.AddRange(new object[] {
            "32",
            "64",
            "130",
            "256",
            "512",
            "1024"});
            this.cbx_PageSize.Location = new System.Drawing.Point(183, 364);
            this.cbx_PageSize.Name = "cbx_PageSize";
            this.cbx_PageSize.Size = new System.Drawing.Size(64, 20);
            this.cbx_PageSize.TabIndex = 10;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.ClientSize = new System.Drawing.Size(729, 392);
            this.Controls.Add(this.cbx_PageSize);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.btn_SelectFile);
            this.Controls.Add(this.txb_FilePath);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.progressBar1);
            this.Name = "Form1";
            this.Text = "IAP升级工具";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btn_Port;
        private System.Windows.Forms.Label lbl_Port;
        private System.Windows.Forms.ProgressBar progressBar1;
        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.Label lbl_Bps;
        private System.Windows.Forms.ComboBox cbx_Port;
        private System.Windows.Forms.ComboBox cbx_Baud;
        private System.Windows.Forms.TextBox txb_FilePath;
        private System.Windows.Forms.Button btn_SelectFile;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button btn_Erase;
        private System.Windows.Forms.Button btn_Upload;
        private System.Windows.Forms.Button btn_RunApp;
        private System.Windows.Forms.Button btn_Config;
        private System.Windows.Forms.TextBox tbx_show;
        private System.Windows.Forms.Button btn_Update;
        private System.Windows.Forms.Button btn_Clear;
        private System.Windows.Forms.Button btn_IAPMenu;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.ComboBox cbx_PageSize;
    }
}

